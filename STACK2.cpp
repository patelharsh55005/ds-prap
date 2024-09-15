#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

int stack[MAX];
int top = -1;

void push(int value);
int pop();
int peep(int position);
void modify(int position, int value);
void display();

int main() {
    int choice, value, position;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peep\n4. Modify\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:	
                value = pop();
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;
            case 3:
                printf("Enter position to peep: ");
                scanf("%d", &position);
                value = peep(position);
                if (value != -1)
                    printf("Value at position %d: %d\n", position, value);
                break;
            case 4:
                printf("Enter position to modify: ");
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &value);
                modify(position, value);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow! Unable to push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed onto stack\n", value);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow! Unable to pop\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int peep(int position) {
    if (top - position + 1 < 0) {
        printf("Invalid position!\n");
        return -1;
    } else {
        return stack[top - position + 1];
    }
}

void modify(int position, int value) {
    if (top - position + 1 < 0) {
        printf("Invalid position!\n");
    } else {
        stack[top - position + 1] = value;
        printf("Value at position %d modified to %d\n", position, value);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

