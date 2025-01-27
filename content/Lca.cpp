struct LCA {
        typedef vector<int> vi;
        int LG, n;
        vector<vi> up;
        vi h;
        LCA(vector<vi> &C)
                : n(sz(C) - 1)
                , LG(__lg(sz(C) - 1))
                , h(sz(C))
                , up(LG + 1, vi(sz(C)))
        {
                dfs(1, 1, C);
                Build();
        }
        void dfs(int u, int pre, vector<vi> &g)
        {
                up[0][u] = pre;
                for (int v : g[u]) {
                        if (v == pre)
                                continue;
                        h[v] = h[u] + 1;
                        dfs(v, u, g);
                }
        }
        void build()
        {
                for (int i = 1; i <= LG; ++i) {
                        for (int j = 1; j <= n; ++j) {
                                up[i][j] = up[i - 1][up[i - 1][j]];
                        }
                }
        }
        int lca(int u, int v)
        {
                if (h[u] < h[v])
                        swap(u, v);
                int need = h[u] - h[v];
                for (int j = LG; j >= 0; --j) {
                        if ((1 << j) & need) {
                                u = up[j][u];
                        }
                }
                if (u == v)
                        return u;
                for (int i = LG; i >= 0; --i) {
                        if (up[i][u] != up[i][v]) {
                                u = up[i][u];
                                v = up[i][v];
                        }
                }
                return up[0][u];
        }
};
