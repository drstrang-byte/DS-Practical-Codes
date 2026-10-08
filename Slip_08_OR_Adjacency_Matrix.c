#include <stdio.h>

int main() {
    int graph[20][20];
    int v, e, i, j, u, w;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(i = 0; i < v; i++)
        for(j = 0; j < v; j++)
            graph[i][j] = 0;

    for(i = 0; i < e; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &w);
        graph[u][w] = 1;
        graph[w][u] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < v; i++) {
        for(j = 0; j < v; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    return 0;
}