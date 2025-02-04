struct H {
	typedef uint64_t ull;
	ull x;
	H(ull x = 0)
		: x(x)
	{
	}
	H operator+(H o)
	{
		return x + o.x + (x + o.x < x);
	}
	H operator-(H o)
	{
		return *this + ~o.x;
	}
	H operator*(H o)
	{
		auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64);
	}
	ull get() const
	{
		return x + !~x;
	}
	bool operator==(H o) const
	{
		return get() == o.get();
	}
	bool operator<(H o) const
	{
		return get() < o.get();
	}
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const H BASE = uniform_int_distribution<int32_t>(666, 999)(rng);
struct Hash {
	vector<H> ha, pw;
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

	H query(int l, int r) // [l,r] inclusive
	{
		return (ha[r] - ha[l - 1] * pw[r - l + 1]);
	}
};
