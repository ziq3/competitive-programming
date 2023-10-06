// stress tested
#define TASK "XPH"
#include <bits/stdc++.h>
using namespace std;
#define el cout << "\n"
#define sz(x) (ll)(x).size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (ll i = a; i <= (b); ++i)
using ll = long long;
using pi = pair<ll, ll>;
const ll N = 4e5 + 111;
ll n, ans = 0, bit[N], m;
void update(ll u) {
  for (; u < N; u |= u + 1) bit[u] += 1;
}
ll query(ll u) {
  ll res = 0;
  u += 1;
  for (; u > 0; u &= u - 1) res += bit[u - 1];
  return res;
}
ll query(ll l, ll r) { return query(r) - query(l - 1); }
struct Query {
  ll l, r, res, idx;
  bool operator<(const Query &other) { return l < other.l; }
};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(TASK ".inp", "r")) {
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
  }
  cin >> n >> m;
  vector<Query> a(n);
  vector<ll> coor;
  {
    ll cnt = 0;
    for (auto &pa : a) {
      pa.idx = ++cnt;
      cin >> pa.l >> pa.r;
      coor.push_back(pa.l);
      coor.push_back(pa.r);
    }
  }
  sort(all(coor));
  coor.erase(unique(all(coor)), coor.end());
  for (auto &pa : a) {
    pa.l = lower_bound(all(coor), pa.l) - coor.begin();
    pa.r = lower_bound(all(coor), pa.r) - coor.begin();
  }
  sort(all(a));
  for (auto &pa : a) {
    pa.res = query(pa.l, N - 1);
    update(pa.r);
  }
  memset(bit, 0, sizeof(bit));
  for (ll i = sz(a) - 1; i >= 0; --i) {
    a[i].res += query(0, a[i].r);
    update(a[i].l);
  }
  sort(all(a), [](Query p1, Query p2) { return p1.idx < p2.idx; });
  for (auto &pa : a) {
    cout << pa.res;
    el;
  }
  return 0;
}