int pow(int x, int e, int mod)
{
        int res = 1;
        for (; e; e /= 2) {
                if (e & 1)
                        (res *= x) %= mod;
                (x *= x) %= mod;
        }
        return res;
}
