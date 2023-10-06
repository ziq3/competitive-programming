// stress tested
#define TASK "COMNUM"
#include <bits/stdc++.h>
using namespace std;
#define el cout << "\n"
#define sz(x) (ll)(x).size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (ll i = a; i <= (b); ++i)
using ll = long long;
typedef pair<ll, ll> pii;
const ll N = 1e5 + 1;
string l, r;
ll dp[N][4];
ll g(char x)
{
    return x - '0';
}
void maxi(ll &x, ll y)
{
    x = max(x, y);
}
ll solve()
{
    reverse(l.begin(), l.end());
    while (sz(l) < sz(r)) l += '0';
    reverse(l.begin(), l.end());
    ll n = sz(r);
    l = " " + l;
    r = " " + r;
    dp[0][0] = 1;
    // 0:x=l=r
    // 1:x>l=r
    // 2:x<r=l
    // 3:x>l<r
    bool ck = 1;
    rep(i, 1, n)
    {
        if (l[i] != '0') ck = 0;
        dp[i][3] = dp[i - 1][3] * 9;
        dp[i][1] = dp[i - 1][1] * g(r[i]);
        dp[i][2] = dp[i - 1][2] * g(l[i]);
        if(l[i]==r[i])
        {
            dp[i][0] = dp[i - 1][0] * g(l[i]);
        }
        if(l[i]+1<r[i])
        {
            maxi(dp[i][3],dp[i-1][0]*g(r[i]-1));
        }
        maxi(dp[i][3], dp[i - 1][1] * g(r[i] - 1));
        maxi(dp[i][3],dp[i-1][2]*9);
        if (l[i] != r[i])
        {
            maxi(dp[i][1],dp[i - 1][0] * g(r[i]));
            maxi(dp[i][2] , dp[i - 1][0] * g(l[i]));
        }
        if (ck)
        {
            if (l[i] == r[i])
            {
                dp[i][0] = 1;
            }
            else
            {
                dp[i][2] = 1;
            }
        }
    }
    return *max_element(dp[n], dp[n] + 4);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(TASK ".inp", "r"))
    {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin >> l >> r;
    cout << solve();
    return 0;
}
