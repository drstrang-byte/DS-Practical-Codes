#include <stdio.h>

int main() {
    int graph[20][20] = {0};
    int v, e, i, j, u, w;
    int in[20] = {0}, out[20] = {0};

    printf("Enter vertices: ");
    scanf("%d", &v);

    printf("Enter edges: ");
    scanf("%d", &e);

    for(i = 0; i < e; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &w);
        graph[u][w] = 1;
        out[u]++;
        in[w]++;
    }

    printf("\nAdjacency List:\n");
    for(i = 0; i < v; i++) {
        printf("%d -> ", i);
        for(j = 0; j < v; j++)
            if(graph[i][j])
                printf("%d ", j);
        printf("\n");
    }

    printf("\nVertex\tIn\tOut\tTotal\n");
    for(i = 0; i < v; i++)
        printf("%d\t%d\t%d\t%d\n", i, in[i], out[i], in[i] + out[i]);

    return 0;
}