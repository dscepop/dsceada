#include <stdio.h>

#define INF 999
int prim(int c[10][10], int n, int s) {
  int v[10], ver[10], d[10], min, u, sum = 0;
  for (int i = 1; i <= n; i++) {
    ver[i] = s;
    d[i] = c[s][i];
    v[i] = 0;
  }
  v[s] = 1;
  for (int i = 1; i <= n - 1; i++) {
    min = INF;
    for (int j = 1; j <= n; j++) {
      if (v[j] == 0 && d[j] < min) {
        min = d[j];
        u = j;
      }
    }
    v[u] = 1;
    sum += d[u];
    printf("\n%d -> %d Cost=%d", ver[u], u, d[u]);
    for (int j = 1; j <= n; j++) {
      if (v[j] == 0 && c[u][j] < d[j]) {
        d[j] = c[u][j];
        ver[j] = u;
      }
    }
  }
  return sum;
}
int main() {
  int c[10][10], n, res, s;
  printf("Enter n value: ");
  scanf("%d", & n);
  printf("Enter the graph data:\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", & c[i][j]);
    }
  }
  printf("Enter the source node: ");
  scanf("%d", & s);
  res = prim(c, n, s);
  printf("\nCost=%d\n", res);
  return 0;
}