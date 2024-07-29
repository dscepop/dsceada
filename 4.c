#include <stdio.h>
#include <limits.h>

void readf();
void SP();
int cost[20][20], dist[20], s[20];
int n, u, min, v;

void readf() {
    int i, j;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INT_MAX; // Use INT_MAX to represent infinity
            }
        }
    }
}

void SP() {
    int i, j, w;
    printf("\nEnter the source vertex: ");
    scanf("%d", &v);

    // Initialize distances and set source distances to 0
    for (i = 1; i <= n; i++) {
        s[i] = 0;
        dist[i] = cost[v][i];
    }
    s[v] = 1;
    dist[v] = 0;

    // Apply Dijkstra's algorithm
    for (i = 1; i < n; i++) {
        min = INT_MAX;

        // Find the vertex with the minimum distance
        for (j = 1; j <= n; j++) {
            if (!s[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        s[u] = 1;

        // Update distances
        for (w = 1; w <= n; w++) {
            if (!s[w] && cost[u][w] != INT_MAX && dist[u] != INT_MAX && (dist[u] + cost[u][w] < dist[w])) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }

    // Print the results
    printf("\nFrom the source vertex %d:\n", v);
    for (i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d -> %d = Infinity\n", v, i);
        } else {
            printf("%d -> %d = %d\n", v, i, dist[i]);
        }
    }
}

int main() {
    readf();
    SP();
    return 0;
}