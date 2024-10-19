#define TASK ""
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
#define el cout << "\n"
#define sz(x) (ll)(x).size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (ll i = a; i <= (b); ++i)
using ll = long long;
using pi = pair<ll, ll>;
const ll N=1e5+1;
ll n;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
    cin >> n;
    return 0;
}
