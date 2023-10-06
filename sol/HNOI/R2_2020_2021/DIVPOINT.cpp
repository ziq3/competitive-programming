#define TASK "DIVPOINT"
#include <bits/stdc++.h>
using namespace std;
#define el cout << "\n"
#define sz(x) (ll)(x).size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (ll i = a; i <= (b); ++i)
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;
const ll N = 1e5 + 1;
struct Point {
  ll x, y;
  bool operator<(const Point &other) {
    if (y == other.y) return x < other.x;
    return y < other.y;
  }
};
ll n;
Point to(Point p1, Point p2) { return {p2.x - p1.x, p2.y - p1.y}; }
ld val(Point p) {
  if (p.y == 0) return p.x * 1e18;
  return (ld)p.x / p.y;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(TASK ".inp", "r")) {
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
  }
  cin >> n;
  vector<Point> a(n);
  for (auto &pa : a) cin >> pa.x >> pa.y;
  sort(all(a));
  Point c = a.front();
  a.erase(a.begin());
  sort(all(a), [c](Point p1, Point p2) {
    Point tp1 = to(c, p1), tp2 = to(c, p2);
    return val(tp1) < val(tp2);
  });
  ll mid = (n - 1) / 2;
  cout << c.x << " " << c.y << " " << a[mid].x << " " << a[mid].y;
  return 0;
}
