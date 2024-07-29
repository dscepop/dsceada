#include <stdio.h>
#define INF 999

int prim(int c[10][10], int n, int s) {
    int v[10], ver[10], d[10];
    int i, j, sum = 0, min, u;

    // Initialize arrays
    for (i = 1; i <= n; i++) {
        ver[i] = s;
        d[i] = c[s][i];
        v[i] = 0;
    }
    v[s] = 1;

    // Apply Prim's algorithm
    for (i = 1; i <= n - 1; i++) {
        min = INF;
        for (j = 1; j <= n; j++) {
            if (v[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        v[u] = 1;
        sum += d[u];
        printf("\n%d -> %d sum=%d", ver[u], u, sum);

        for (j = 1; j <= n; j++) {
            if (v[j] == 0 && c[u][j] < d[j]) {
                d[j] = c[u][j];
                ver[j] = u;
            }
        }
    }
    return sum;
}

int main() {
    int c[10][10], i, j, res, s, n;

    printf("\nEnter n value: ");
    scanf("%d", &n);
    printf("\nEnter the graph data:\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if (c[i][j] == 0 && i != j) {
                c[i][j] = INF;
            }
        }
    }

    printf("\nEnter the source node: ");
    scanf("%d", &s);

    res = prim(c, n, s);
    printf("\nCost = %d\n", res);

    return 0;
}