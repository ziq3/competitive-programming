struct Info {
        int val = 0;
        Info() {};
        Info(int x)
        {
                val = x;
        }
        Info operator+(const Info &other)
        {
                Info res = *this;
                res.val += other.val;
                return res;
        }
};
struct SegmentTree {
        int n;
        vector<Info> a;
        SegmentTree(int _n)
                : n(_n)
                , a(n * 2) {};
        void set(int pos, Info val)
        {
                for (a[pos += n] = val; pos /= 2;)
                        a[pos] = a[pos * 2] + a[pos * 2 + 1];
        }
        Info query(int l, int r) // [l,r] inclusive
        {
                Info res = Info();
                for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
                        if (l % 2)
                                res = res + a[l++];
                        if (r % 2)
                                res = a[--r] + res;
                }
                return res;
        }
};
