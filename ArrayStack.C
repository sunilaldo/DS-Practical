#include <stdio.h>
#include <conio.h> // For getch() function in Turbo C
#include <stdlib.h> // For exit() function

#define MAX 5 // Define maximum size of the stack

int stack[MAX]; // Array to store stack elements
int top = -1;   // Initialize top of stack as -1 (empty stack)

// Function prototypes
void push(int);
void pop();
void display();

int main() { // Corrected from void main to int main
    int choice, value;

    printf("ARRAY IMPLEMENTATION OF STACK\n\n");

    while (1) {
        printf("*************************\n");
        printf("*        MAIN MENU      *\n");
        printf("*************************\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push operation
                printf("Enter a value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2: // Pop operation
                pop();
                break;

            case 3: // Display stack
                display();
                break;

            case 4: // Exit program
                printf("Thank you for using the program. Exiting...\n");
                getch();  // Used to keep the window open in Turbo C
                return 0;  // Exit the program
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0; // Return from main function
}

// Push function
void push(int value) {
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot push %d.\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("\n%d pushed onto the stack.\n", value);
    }
}

// Pop function
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! No elements to pop.\n");
    } else {
        printf("\n%d popped from the stack.\n", stack[top]);
        top--;
    }
}

// Display function
void display() {
    int i;  // Declare 'i' here for the loop
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack contents:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
