const int LG = 17;
int up[LG + 1][N], h[N];
int Lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  ll need = h[u] - h[v];
  for (int j = LG; j >= 0; --j) {
    if ((1 << j) & need) {
      u = up[j][u];
    }
  }
  if (u == v) return u;
  for (int i = LG; i >= 0; --i) {
    if (up[i][u] != up[i][v]) {
      u = up[i][u];
      v = up[i][v];
    }
  }
  return up[0][u];
}
void Dfs(int u, int pre) {
  up[0][u] = pre;
  for (int v : g[u]) {
    if (v == pre) continue;
    h[v] = h[u] + 1;
    dfs(v, u);
  }
}
void Init() {
  for (int i = 1; i <= LG; ++i) {
    for (int j = 1; j <= n; ++j) {
      up[i][j] = up[i - 1][up[i - 1][j]];
    }
  }
}
