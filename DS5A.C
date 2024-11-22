#include <stdio.h>
#include <conio.h> // Required for Turbo C

#define V 5

// Initialize matrix to 0
void init(int arr[][V]) {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            arr[i][j] = 0; // Explicitly set each element to 0
        }
    }
}

// Add edge: Set arr[src][dest] = 1
void addEdge(int arr[][V], int src, int dest) {
    arr[src][dest] = 1;
}

// Print adjacency matrix
void printAdjMatrix(int arr[][V]) {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[V][V]; // Declare adjacency matrix
    init(adjMatrix);     // Initialize matrix to 0

    // Add edges to adjacency matrix
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 4);

    // Print adjacency matrix
    printf("Adjacency Matrix:\n");
    printAdjMatrix(adjMatrix);

    getch(); // Pause to keep the output visible in Turbo C
    return 0;
}
