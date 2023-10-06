#define TASK "SUMDIV"
#include <bits/stdc++.h>
using namespace std;
#define el cout << "\n"
#define sz(x) (ll)(x).size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (ll i = a; i <= (b); ++i)
using ll = long long;
using pi = pair<ll,ll>;
const ll N = 1e5 + 1;
ll sum(ll l,ll r)
{
    return (r-l+1)*(l+r)/2;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll l,r,hBound,ans=0;
    cin >> l>>r;
    hBound=r+1;
    for(ll i=1;i*i<=r;++i)
    {
        ll low=(l+i-1)/i,high=r/i;
        high=min(hBound,high);
        if(r/i>(l-1)/i)ans+=i;
        low=max(low,(ll)sqrtl(r)+1);
        if(low<=high)
        {
            ans+=sum(low,high);
            hBound=low-1;
        }
    }
    cout<<ans;
    return 0;
}
