struct Info {
        int val = 0;
        int size = 1;
        Info()
        {
        }
        Info(int x)
        {
                val = x;
        }
        Info operator+(const Info &other)
        {
                Info res = *this;
                res.val += other.val;
                res.size += other.size;
                return res;
        }
};
struct LazySegmentTree {
        int n;
        vector<Info> a;
        vector<int> lazy;

        LazySegmentTree(int _n)
                : n(_n)
                , a(2 * n)
                , lazy(n, 0)
        {
                for (int i = n - 1; i > 0; --i) {
                        a[i] = a[i * 2] + a[i * 2 + 1];
                }
        }

        void push(int leaf)
        {
                for (int h = log2(n) + 1; h > 0; --h) {
                        int i = leaf >> h;
                        if (lazy[i]) {
                                a[i * 2].val += lazy[i] * a[i * 2].size;
                                a[i * 2 + 1].val += lazy[i] * a[i * 2 + 1].size;
                                if ((i * 2) < n)
                                        lazy[i * 2] += lazy[i];
                                if ((i * 2 + 1) < n)
                                        lazy[i * 2 + 1] += lazy[i];
                                lazy[i] = 0;
                        }
                }
        }

        void update(int ql, int qr, int val)
        {
                int l = ql + n, r = qr + n;
                int l0 = l, r0 = r; // Store original values of l and r
                push(l);
                push(r);

                for (; l <= r; l /= 2, r /= 2) {
                        if (l % 2 == 1) {
                                a[l].val += val * a[l].size;
                                if (l < n)
                                        lazy[l] += val;
                                l++;
                        }
                        if (r % 2 == 0) {
                                a[r].val += val * a[r].size;
                                if (r < n)
                                        lazy[r] += val;
                                r--;
                        }
                }

                for (l0 /= 2, r0 /= 2; l0 > 0 || r0 > 0; l0 /= 2, r0 /= 2) {
                        if (l0 > 0)
                                a[l0] = a[l0 * 2] + a[l0 * 2 + 1];
                        if (r0 > 0)
                                a[r0] = a[r0 * 2] + a[r0 * 2 + 1];
                }
        }

        Info query(int ql, int qr)
        {
                int l = ql + n, r = qr + n;
                push(l);
                push(r);
                Info res = Info();
                for (; l <= r; l /= 2, r /= 2) {
                        if (l % 2 == 1)
                                res = res + a[l++];
                        if (r % 2 == 0)
                                res = res + a[r--];
                }
                return res;
        }
};
