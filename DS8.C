#include <stdio.h>
#include <conio.h> // Required for Turbo C

// Method to find factorial using recursion
int factorialUsingRecursion(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorialUsingRecursion(n - 1); // Recursive call
}

// Method to find factorial using iteration
int factorialUsingIteration(int n) {
    int res = 1;
    int i; // Declare variables at the beginning
    for (i = 2; i <= n; i++) {
        res *= i; // Iterative multiplication
    }
    return res;
}

// Main function
int main() {
    int num = 5; // Input number

    // Output factorial using recursion
    printf("Factorial of %d using Recursion is: %d\n", num, factorialUsingRecursion(num));

    // Output factorial using iteration
    printf("Factorial of %d using Iteration is: %d\n", num, factorialUsingIteration(num));

    getch(); // Pause to keep the output visible
    return 0;
}
