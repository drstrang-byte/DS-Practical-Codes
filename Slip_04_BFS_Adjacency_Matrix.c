#include <stdio.h>

int main() {
    int graph[20][20] = {0};
    int queue[20], visited[20] = {0};
    int v, e, u, w, start;
    int front = 0, rear = -1;
    int i, j, current;

    printf("Enter vertices: ");
    scanf("%d", &v);

    printf("Enter edges: ");
    scanf("%d", &e);

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

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS: ");

    while(front <= rear) {
        current = queue[front++];
        printf("%d ", current);

        for(i = 0; i < v; i++) {
            if(graph[current][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}