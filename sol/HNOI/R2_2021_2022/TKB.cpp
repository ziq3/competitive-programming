// sub
// k=1
// n<=20
#define TASK "TKB"
#include <bits/stdc++.h>
using namespace std;
#define el cout << "\n"
#define sz(x) (ll)(x).size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (ll i = a; i <= (b); ++i)
using ll = long long;
using pi = pair<ll, ll>;
const ll N = 21;
ll n, k, ans = 0;
vector<ll> a;
map<ll, ll> g[N];
namespace diameter {
vector<ll> d;
void dfs(ll u, ll pre) {
  for (auto pa : g[u]) {
    ll v = pa.first;
    if (v == pre) continue;
    d[v] = d[u] + 1;
    dfs(v, u);
  }
}
void solve() {
  d.resize(n + 1);
  dfs(1, 1);
  ll u = max_element(all(d)) - d.begin();
  d[u] = 0;
  dfs(u, u);
  cout << *max_element(all(d));
}
}  // namespace diameter
void dfs(ll u, map<ll, ll> adj[N], vector<ll> b, ll sum) {
  ans = max(ans, sum);
  for (auto &pa : adj[u]) {
    if (pa.second && adj[pa.first][u] && b[pa.first]) {
      --b[pa.first];
      --adj[pa.first][u];
      --pa.second;
      dfs(pa.first, adj, b, sum + 1);
      ++b[pa.first];
      ++adj[pa.first][u];
      ++pa.second;
    }
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(TASK ".inp", "r")) {
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
  }
  cin >> n >> k;
  rep(i, 1, n - 1) {
    ll u, v;
    cin >> u >> v;
    g[u][v] = 2;
    g[v][u] = 2;
  }
  if (k == 1) {
    diameter::solve();
    return 0;
  }
  a.assign(n + 1, k);
  rep(i, 1, n) {
    --a[i];
    dfs(i, g, a, 0);
    ++a[i];
  }
  cout << ans;
  return 0;
}
