#include <stdio.h>
#include <conio.h> // Required for Turbo C
#define MAX 100
#define INF 9999 // Define a large constant for infinity

int n;               // Number of vertices in the graph
int graph[MAX][MAX]; // Adjacency matrix representation of the graph

// Function to find the vertex with the minimum distance
int minDistance(int dist[], int visited[]) {
    int min = INF, min_index = -1;
    int v;
    for (v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int src) {
    int dist[MAX];
    int visited[MAX];
    int i, count, u, v;

    // Initialize distances and visited array
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (count = 0; count < n - 1; count++) {
        u = minDistance(dist, visited);
        visited[u] = 1;

        for (v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the result
    printf("Vertex \t Distance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int edges, u, v, w, src;
    int i, j, m;

    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (m = 0; m < edges; m++) {
        printf("Enter edge (u v w): ");
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Uncomment this line if the graph is undirected
    }

    // Input the source vertex
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    // Call Dijkstra's algorithm
    dijkstra(src);

    getch(); // Pause to keep the output visible
    return 0;
}
