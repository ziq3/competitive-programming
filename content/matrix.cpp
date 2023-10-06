template <int N>
struct Matrix {
  typedef Matrix M;
  array<array<ll, N>, N> d{};
  M operator*(const M& m) const {
    M a;
    rep(i, 0, N - 1) rep(j, 0, N - 1) rep(k, 0, N - 1) a.d[i][j] +=
        d[i][k] * m.d[k][j];
    return a;
  }
  M operator^(ll p) const {
    M a, b(*this);
    rep(i, 0, N - 1) a.d[i][i] = 1;
    while (p) {
      if (p & 1) a = a * b;
      b = b * b;
      p >>= 1;
    }
    return a;
  }
};
