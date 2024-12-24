struct SparseTable {
    static constexpr ll MAXSIZE=1e5,MAXLOG=16;
    array<array<ll,MAXSIZE>,MAXLOG> a;

    ll F(ll x,ll y){return min(x,y);}

    void Build()
    {
        rep(i,1,MAXLOG)
        {
            for(ll j=1;j+(1<<i)-1<=MAXSIZE;++j)
            {
                a[i][j]=F(a[i-1][j],a[i-1][j+(1<<(i-1))]);
            }
        }
    }
    ll Query(ll l,ll r)
    {
        ll lg=__lg(r-l+1);
        return F(a[lg][l],a[lg][r-(1<<lg)+1]);
    }
};
