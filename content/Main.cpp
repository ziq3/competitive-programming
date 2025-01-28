#include <bits/stdc++.h>
using namespace std;
#define print_op(...) ostream &operator<<(ostream &out, const __VA_ARGS__ &u)
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
        return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container,
          typename T = typename enable_if<!is_same<T_container, string>::value,
                                          typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
        os << '{';
        string sep;
        for (const T &x : v)
                os << sep << x, sep = ", ";
        return os << '}';
}

void dbg_out()
{
        cout << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T)
{
        cout << ", " << H;
        dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define el cout << "\n"
#define sz(x) (long long)(x).size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (long long i = a; i <= (b); ++i)
#define int long long
const int N = 1e5 + 1;
using pi = pair<int, int>;
void solve()
{
        int n;
        cin >> n;
}
signed main()
{
        cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
#endif
        int tc = 1;
        cin >> tc;
        rep(i, 1, tc) {
                // cout<<"# Test case : "<<i;el;
                solve();
                el;
        }
        return 0;
}
