struct Mint {
	static const int MOD = 1e9 + 7;
	int v;
	explicit operator int() const
	{
		return v;
	}
	Mint()
		: v(0)
	{
	}
	Mint(int _v)
		: v(_v % MOD)
	{
		if (v < 0)
			v += MOD;
	}
	bool operator==(const Mint &oth) const
	{
		return v == oth.v;
	}
	Mint &operator+=(const Mint &oth)
	{
		if ((v += oth.v) >= MOD)
			v -= MOD;
		return *this;
	}
	Mint &operator-=(const Mint &oth)
	{
		if ((v -= oth.v) < 0)
			v += MOD;
		return *this;
	}
	Mint &operator*=(const Mint &oth)
	{
		v = (v * oth.v) % MOD;
		return *this;
	}
	Mint operator+(const Mint &oth) const
	{
		Mint res = *this;
		res += oth;
		return res;
	}
	Mint operator-(const Mint &oth) const
	{
		Mint res = *this;
		res -= oth;
		return res;
	}
	Mint operator*(const Mint &oth) const
	{
		return Mint(v * oth.v);
	}
	Mint pow(int p) const
	{
		Mint res = 1, a = *this;
		while (p > 0) {
			if (p & 1)
				res *= a;
			a *= a;
			p >>= 1;
		}
		return res;
	}
	Mint inv() const
	{
		return pow(MOD - 2);
	}
	Mint operator/(const Mint &oth) const
	{
		return *this * oth.inv();
	}
	friend ostream &operator<<(ostream &out, const Mint &a)
	{
		return out << a.v;
	}
};
