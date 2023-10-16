struct FT
{
    vector<ll>s;
    FT(ll _n):s(_n) {};
    void update(ll pos,ll val)
    {
        for(; pos<sz(s); pos+=pos&-pos)s[pos]+=val;
    }
    ll query(ll pos)
    {
        ll res=0;
        for(; pos>0; pos-=pos&-pos)res+=s[pos];
        return res;
    }
    ll query(ll l,ll r)
    {
        return query(r)-query(l-1);
    }
};
