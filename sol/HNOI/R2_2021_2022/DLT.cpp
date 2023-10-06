// sub 1,2,3,4
// stress tested
#define TASK "DLT"
#include <bits/stdc++.h>
using namespace std;
#define el cout << "\n"
#define sz(x) (ll)(x).size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (ll i = a; i <= (b); ++i)
using ll = long long;
using pi = pair<ll, ll>;
const ll N = 1e5 + 1;
ll n, a[N], q;
ll mx = 0;
void brute() {
  while (q--) {
    ll l, r, k, cnt = 0;
    cin >> l >> r >> k;
    map<ll, ll> mp;
    rep(i, l, r) { mp[a[i]] += (r - i + 1) * (i - l + 1); }
    for (auto &pa : mp) {
      cnt += pa.second;
      if (cnt >= k) {
        cout << pa.first;
        el;
        break;
      }
    }
  }
}
namespace sub_a {
vector<ll> g[5001], pref_sqr[5001], pref[5001];
ll get_sum(ll l, ll r, vector<ll> &pref) { return pref[r] - pref[l - 1]; }
void solve() {
  rep(i, 1, mx) {
    g[i].push_back(0);
    pref[i].push_back(0);
    pref_sqr[i].push_back(0);
  }
  rep(i, 1, n) {
    g[a[i]].push_back(i);
    pref[a[i]].push_back(pref[a[i]].back() + i);
    pref_sqr[a[i]].push_back(pref_sqr[a[i]].back() + i * i);
  }
  while (q--) {
    ll l, r, k;
    cin >> l >> r >> k;
    //(r-l+1-l*r)+l*i-i^2+i*r
    vector<ll> cnt(mx + 1);
    rep(i, 1, mx) {
      ll sum = 0;
      ll lef = lower_bound(all(g[i]), l) - g[i].begin();
      ll rig = upper_bound(all(g[i]), r) - g[i].begin() - 1;
      if (lef > rig) continue;
      sum += (rig - lef + 1) * (r - l + 1 - l * r);
      sum -= get_sum(lef, rig, pref_sqr[i]);
      sum += (l + r) * get_sum(lef, rig, pref[i]);
      cnt[i] += sum;
    }
    ll cur = 0;
    rep(i, 1, mx) {
      cur += cnt[i];
      if (cur >= k) {
        cout << i;
        el;
        break;
      }
    }
  }
}
}  // namespace sub_a
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(TASK ".inp", "r")) {
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
  }
  cin >> n >> q;
  rep(i, 1, n) cin >> a[i], mx = max(mx, a[i]);
  if (q <= 5000) {
    brute();
    return 0;
  }
  sub_a::solve();
  return 0;
}
