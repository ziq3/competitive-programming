struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) {  // a[pos] += dif
    for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) {  // sum of values in [0, pos]
    pos += 1;
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
};