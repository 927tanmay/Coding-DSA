ll mulmod(ll a, ll b, ll m)
{
    ll ans = 0;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ans + a) % m;
            b--;
        }
        a = (2 * a) % m;
        b = b / 2;
    }
    return ans;
}