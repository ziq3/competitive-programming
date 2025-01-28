mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int BASE = uniform_int_distribution<int32_t>(331, 999)(rng);
struct Hash {
        vector<Mint> ha, pw;
        Hash(string &str)
                : ha(sz(str) + 1)
                , pw(ha)
        {
                pw[0] = 1;
                rep(i, 0, sz(str) - 1) {
                        ha[i + 1] = ha[i] * BASE + str[i];
                        pw[i + 1] = pw[i] * BASE;
                }
        }
        int query(int a, int b)
        { // hash [a, b]
                return (int)(ha[b + 1] - ha[a] * pw[b - a + 1]);
        }
};
