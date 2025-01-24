#include <bits/stdc++.h>
using namespace std;
#define print_op(...) ostream &operator<<(ostream &out, const __VA_ARGS__ &u)
#define db(val) "[" #val " = " << (val) << "] "
template <class U, class V> print_op(pair<U, V>) {
  return out << "(" << u.first << ", " << u.second << ")";
}
template <class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream &>::type
operator<<(ostream &out, const Con &con) {
  out << "{";
  for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
    out << (it == beg ? "" : ", ") << *it;
  return out << "}";
}
#define el cout << "\n"
#define sz(x) (long long)(x).size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (long long i = a; i <= (b); ++i)
#define int long long
const int N = 1e5 + 1;
using pi = pair<int, int>;
void solve() {
  int n;
  cin >> n;
}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
  freopen(".inp", "r", stdin);
  freopen(".out", "w", stdout);
#endif
  int tc;
  cin >> tc;
  rep(i, 1, tc) {
    // cout<<"# Test case : "<<i;el;
    solve();
    el;
  }
  return 0;
}
