#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
#define INF 1e9
#define mod 1000000007

ll max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

ll power(ll a, ll n, ll modi)
{
    ll ans = 1;

    while (n)
    {
        if (n % 2 == 1)
        {
            ans = ((ans % modi) * (a % modi)) % modi;
            n--;
        }
        a = ((a % modi) * (a % modi)) % modi;
        n = n / 2;
    }
    return ans % modi;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;

        ll y = (a - b);

        ll tmp = 1;
        ll x = (power(a, n, mod) + power(b, n, mod)) % mod;

        if (y == 0)
            tmp = x;
        else
        {
            for (ll i = 1; i * i <= y; i++)
            {
                if (y % i == 0)
                {
                    x = (power(a, n, i) + power(b, n, i)) % i;

                    if (x == 0)
                    {

                        tmp = max(tmp, i);
                    }
                    x = (power(a, n, y / i) + power(b, n, y / i)) % (y / i);

                    if (x == 0)
                    {

                        tmp = max(tmp, y / i);
                    }
                }
            }
        }
        cout << tmp % mod << endl;
    }
    return 0;
}