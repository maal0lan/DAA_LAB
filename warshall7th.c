#include <stdio.h>

int max(int a, int b){ return (a > b) ? a : b; }

void warshal(int p[10][10], int n) {
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                p[i][j] = max(p[i][j], p[i][k] && p[k][j]);
}

int main() {
    int p[10][10] = {0}, n, e, u, v, i, j;

    printf("Vertices: ");
    scanf("%d", &n);
    printf("Edges: ");
    scanf("%d", &e);

    for (i = 1; i <= e; i++) {
        printf("Edge %d (u v): ", i);
        scanf("%d%d", &u, &v);
        p[u][v] = 1;
    }

    warshal(p, n);

    printf("Transitive Closure:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }
    return 0;
}
