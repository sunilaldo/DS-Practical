#include <stdio.h>
#include <conio.h> // Required for Turbo C

#define MAX 100
#define INF 9999 // Replace INT_MAX with a large constant

// Function to compute the minimum number of multiplications
int MatrixChainOrder(int p[], int n) {
    int m[MAX][MAX]; // Using static memory for compatibility
    int i, j, k, L, q;

    // Initialize the diagonal of the matrix to zero
    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // L is the chain length
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INF; // Initialize with a large value
            for (k = i; k <= j - 1; k++) {
                // Calculate the cost
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q; // Update minimum cost
                }
            }
        }
    }

    return m[1][n - 1]; // Return the result
}

// Main function
int main() {
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Output the result
    printf("Minimum number of multiplications is %d", MatrixChainOrder(arr, size));

    getch(); // Pause to keep the output visible
    return 0;
}
