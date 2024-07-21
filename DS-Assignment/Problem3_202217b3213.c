#include <stdio.h>

// Global variables
int stack[100];  // Stack array with maximum size 100
int top = -1;     // Initialize top of stack

// Function prototypes
void push(void);
void pop(void);
void display(void);

int main() {
    int choice;

    printf("\n Enter the size of STACK [MAX=100]: ");
    scanf("%d", &top);  // Read size of stack (assuming this is intended for defining max size)

    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");

    do {
        printf("\n Enter the Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\t EXIT POINT ");
                break;
            default:
                printf("\n\t Please Enter a Valid Choice (1/2/3/4)");
        }
    } while (choice != 4);

    return 0;
}

void push() {
    int x;

    if (top >= 99) {
        printf("\n\t STACK is overflow");
    } else {
        printf("\n Enter a value to be pushed: ");
        scanf("%d", &x);
        stack[++top] = x;  // Increment top and then push the value onto the stack
    }
}

void pop() {
    if (top <= -1) {
        printf("\n\t Stack is underflow");
    } else {
        printf("\n\t The popped element is %d", stack[top--]);  // Pop the top element and decrement top
    }
}

void display() {
    if (top >= 0) {
        printf("\n The elements in STACK: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("\n The STACK is empty\n");
    }
}
