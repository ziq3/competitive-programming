struct Info {
        ll maxSub, minSub, maxAdd, minAdd, maxSum;
        Info() {};
        Info(int x, int p)
        {
                maxSub = x - p;
                minSub = x - p;
                maxAdd = x + p;
                minAdd = x + p;
                maxSum = 0;
        }
        Info operator+(const Info &other)
        {
                Info res(0, 0);
                res.maxSub = max(maxSub, other.maxSub);
                res.minSub = min(minSub, other.minSub);
                res.maxAdd = max(maxAdd, other.maxAdd);
                res.minAdd = min(minAdd, other.minAdd);
                res.maxSum = max({ maxSum, other.maxSum, maxAdd - other.minAdd,
                                   other.maxSub - minSub });
                return res;
        }
};
struct Tree {
        Tree(int n)
                : a(n * 4) {};
        vector<Info> a;
        void build(int id, int l, int r, vector<Info> &b)
        {
                if (l == r) {
                        a[id] = b[l];
                        return;
                }
                int mid = (l + r) / 2;
                build(id * 2, l, mid, b);
                build(id * 2 + 1, mid + 1, r, b);
                a[id] = a[id * 2] + a[id * 2 + 1];
        }
        void update(int id, int l, int r, int p, Info v)
        {
                if (l == r) {
                        a[id] = v;
                        return;
                }
                int mid = (l + r) / 2;
                if (p <= mid) {
                        update(id * 2, l, mid, p, v);
                } else {
                        update(id * 2 + 1, mid + 1, r, p, v);
                }
                a[id] = a[id * 2] + a[id * 2 + 1];
        }
        Info query(int id, int l, int r, int u, int v)
        {
                if (l >= u && r <= v) {
                        return a[id];
                }
                int mid = (l + r) / 2;
                return query(id * 2, l, mid, u, v) +
                       query(id * 2 + 1, mid + 1, r, u, v);
        }
};
