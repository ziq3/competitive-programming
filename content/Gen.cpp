#define TASK ""
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l,ll r)
{
    return uniform_int_distribution<int>(l,r)(rng);
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return 0;
}
