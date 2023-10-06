int walk(ll x) {
  int id = 1, l = 1, r = 2e6;
  while (1) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    id *= 2;
    if (st[id] < x) {
      x -= st[id];
      l = mid + 1;
      ++id;
    } else {
      r = mid;
    }
  }
}
