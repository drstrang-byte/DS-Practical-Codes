#include <stdio.h>

struct Edge {
    int u, v, cost;
};

int parent[20];

int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    struct Edge edge[50], temp;
    int n, e, i, j, count = 0, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(i = 0; i < e; i++) {
        printf("Enter u v cost: ");
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].cost);
    }

    for(i = 0; i < e - 1; i++) {
        for(j = i + 1; j < e; j++) {
            if(edge[i].cost > edge[j].cost) {
                temp = edge[i];
                edge[i] = edge[j];
                edge[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in MST:\n");

    for(i = 0; i < e && count < n - 1; i++) {
        int u = edge[i].u;
        int v = edge[i].v;

        if(find(u) != find(v)) {
            printf("%d - %d = %d\n", u, v, edge[i].cost);
            total += edge[i].cost;
            unionSet(u, v);
            count++;
        }
    }

    printf("Minimum cost = %d\n", total);

    return 0;
}