#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void add(int arr[], int *size, int value);
void delet(int arr[], int *size, int index);
void modify(int arr[], int size, int index, int value);
void sort(int arr[], int size);
int simpleSearch(int arr[], int size, int value);
int binarySearch(int arr[], int size, int value);
void display(int arr[], int size);

int main() {
    int arr[MAX];
    int size = 0;
    int choice, value, index, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Sort\n");
        printf("5. Simple Search\n");
        printf("6. Binary Search\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (size >= MAX) {
                    printf("Array is full\n");
                } else {
                    printf("Enter value to add: ");
                    scanf("%d", &value);
                    add(arr, &size, value);
                }
                break;
            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                if (index < 0 || index >= size) {
                    printf("Invalid index\n");
                } else {
                    delet(arr, &size, index);
                }
                break;
            case 3:
                printf("Enter index to modify: ");
                scanf("%d", &index);
                if (index < 0 || index >= size) {
                    printf("Invalid index\n");
                } else {
                    printf("Enter new value: ");
                    scanf("%d", &value);
                    modify(arr, size, index, value);
                }
                break;
            case 4:
                sort(arr, size);
                printf("Array sorted\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pos = simpleSearch(arr, size, value);
                if (pos != -1) {
                    printf("Value %d found at index %d\n", value, pos);
                } else {
                    printf("Value %d not found\n", value);
                }
                break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);
                sort(arr, size);  // Ensure array is sorted before binary search
                pos = binarySearch(arr, size, value);
                if (pos != -1) {
                    printf("Value %d found at index %d\n", value, pos);
                } else {
                    printf("Value %d not found\n", value);
                }
                break;
            case 7:
                display(arr, size);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void add(int arr[], int *size, int value) {
    arr[*size] = value;
    (*size)++;
}

void delet(int arr[], int *size, int index) {
    for (int i = index; i < (*size) - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void modify(int arr[], int size, int index, int value) {
    arr[index] = value;
}

void sort(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int simpleSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int value) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

