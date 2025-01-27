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
struct Tree {
        int n;
        Tree(int _n)
                : a(_n * 2)
                , n(_n) {};
        vector<Info> a;
        void update(int pos, Info val)
        {
                for (a[pos += n] = val; pos /= 2;)
                        a[pos] = a[pos * 2] + a[pos * 2 + 1];
        }
        Info query(int b, int e)
        {
                e += 1;
                Info ra = Info(), rb = Info();
                for (b += n, e += n; b < e; b /= 2, e /= 2) {
                        if (b % 2)
                                ra = ra + a[b++];
                        if (e % 2)
                                rb = a[--e] + rb;
                }
                return ra + rb;
        }
};
