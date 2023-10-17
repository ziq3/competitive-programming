struct FT
{
    vector<ll>s;
    FT(ll _n):s(_n) {};
    void Update(ll pos,ll val)
    {
        for(; pos<sz(s); pos+=pos&-pos)s[pos]+=val;
    }
    ll Query(ll pos)
    {
        ll res=0;
        for(; pos>0; pos-=pos&-pos)res+=s[pos];
        return res;
    }
    ll Query(ll l,ll r)
    {
        return Query(r)-Query(l-1);
    }
};
