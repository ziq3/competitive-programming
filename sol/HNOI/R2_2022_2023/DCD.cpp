#define TASK "DCD"
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
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    cin>>n;
    for(ll i=min(44721ll,n); i>=2; --i)
    {
        if(n*2%i!=0)continue;
        for(ll j=1; (j+1)*i/2<=n; ++j)
        {
            ll d=n*2/i-j-j;
            if(d%(i-1)!=0)continue;
            d/=i-1;
            if(d==0)continue;
            rep(z,1,i)
            {
                cout<<j+(z-1)*d<<" ";
            }
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
