#include <stdio.h>

#define INF 9999

int main() {
    int cost[20][20], visited[20] = {0};
    int n, i, j, edges = 0;
    int min, u = 0, v = 0, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;

    printf("\nEdges in MST:\n");

    while(edges < n - 1) {
        min = INF;

        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", u, v, min);
        total += min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum cost = %d\n", total);

    return 0;
}