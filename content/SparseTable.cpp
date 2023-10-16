template<class B>
struct Sparse : public B
{
    array<array<ll,N>,17>node;
    void init()
    {
        rep(i,1,16)
        {
            for(ll j=1;j+(1<<i)-1<=n;++j)
            {
                node[i][j]=B::OP(node[i-1][j],node[i-1][j+(1<<(i-1))]);
            }
        }
    }
    ll query(ll l,ll r)
    {
        ll lg=log2(r-l+1);
        return B::OP(node[lg][l],node[lg][r-(1<<lg)+1]);
    }
};
