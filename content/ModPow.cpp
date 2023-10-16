ll Pow(ll x, ll e, ll mod) {
  ll res = 1;
  for (; e; e /= 2) {
    if (e & 1) (res *= x) %= mod;
    (x *= x) %= mod;
  }
  return res;
}
