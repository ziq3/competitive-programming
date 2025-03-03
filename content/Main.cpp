#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "Debug.h"
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
