#include<stdio.h>
#include<conio.h>  // Required for Turbo C to use getch()

int main()
{
    int i, j, k, n, a[10][10], indeg[10], flag[10], count = 0;

    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        printf("Enter row %d:\n", i + 1);
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Initialize indegree and flag arrays
    for (i = 0; i < n; i++) {
        indeg[i] = 0;
        flag[i] = 0;
    }

    // Calculate indegree of each vertex
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            indeg[i] += a[j][i];
        }
    }

    printf("\nThe topological order is: ");
    while (count < n) {
        for (k = 0; k < n; k++) {
            if (indeg[k] == 0 && flag[k] == 0) {
                printf("%d ", (k + 1));
                flag[k] = 1;

                // Decrease indegree of connected vertices
                for (i = 0; i < n; i++) {
                    if (a[k][i] == 1) {
                        indeg[i]--;
                    }
                }
            }
        }
        count++;
    }

    getch();  // Required for Turbo C to keep the output screen visible
    return 0;
}
