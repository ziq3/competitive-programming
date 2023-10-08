// sub 1,2,3,4
// stress tested
#pragma GCC target("avx2")
#pragma GCC optimize("03", "unroll-loops")
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
    ll l, r, k;
    cin >> l >> r >> k;
    unordered_map<ll, ll> mp;
    mp.max_load_factor(0.25);
    rep(i, l, r) { mp[a[i]] += (r - i + 1) * (i - l + 1); }
    vector<pi> cnt;
    for (auto pa : mp) cnt.push_back(pa);
    sort(all(cnt));
    ll cur = 0;
    for (auto pa : cnt) {
      cur += pa.second;
      if (cur >= k) {
        cout << pa.first;
        el;
        break;
      }
    }
  }
}
namespace sub_a {
void solve() {
  vector<vector<ll>> pref(n + 1, vector<ll>(mx));
  vector<vector<ll>> pref_i(n + 1, vector<ll>(mx));
  vector<vector<ll>> pref_sqr(n + 1, vector<ll>(mx));
  rep(i, 1, n) {
    pref[i][a[i]] += 1;
    pref_i[i][a[i]] += i;
    pref_sqr[i][a[i]] += i * i;
    rep(j, 1, mx) {
      pref[i][j] += pref[i - 1][j];
      pref_i[i][j] += pref_i[i - 1][j];
      pref_sqr[i][j] += pref_sqr[i - 1][j];
    }
  }
  while (q--) {
    ll l, r, k;
    cin >> l >> r >> k;
    ll x = (r - l + 1 - l * r);
    //(r-l+1-l*r)+l*i-i^2+i*r
    vector<ll> cnt(mx + 1);
    rep(i, 1, mx) {
      ll sum = 0;
      sum += (pref[r][i] - pref[l - 1][i]) * x;
      sum -= pref_sqr[r][i] - pref_sqr[l - 1][i];
      sum += (l + r) * (pref_i[r][i] - pref_i[l - 1][i]);
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
  if (n <= 5000 && q <= 5000) {
    brute();
    return 0;
  }
  sub_a::solve();
  return 0;
}
