struct FT {
        vector<int> s;
        FT(int n)
                : s(n)
        {
        }
        void update(int pos, int dif)
        {
                for (; pos < sz(s); pos |= pos + 1)
                        s[pos] += dif;
        }
        int query(int pos)
        {
                pos += 1;
                int res = 0;
                for (; pos > 0; pos &= pos - 1)
                        res += s[pos - 1];
                return res;
        }
        int query(int l, int r)
        {
                return query(r) - query(l - 1);
        }
};
