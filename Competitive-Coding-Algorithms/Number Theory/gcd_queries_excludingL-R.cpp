#include <bits/stdc++.h>
using namespace std;
#define ll int
#define REP(i, n) for (int i = 1; i <= n; i++)
#define endl '\n'
#define INF 1e9
#define mod 1000000007

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        ll a[n + 1];

        REP(i, n)
            cin >> a[i];

        ll tmp1[n + 1], rev[n + 1], res = 0;
        tmp1[0] = 0;
        rev[0] = 0;
        REP(i, n)
        {
            res = gcd(res, a[i]);
            tmp1[i] = res;
        }
        res = 0;
        for (ll i = n; i >= 1; i--)
        {
            res = gcd(res, a[i]);
            rev[i] = res;
        }

        while (q--)
        {
            ll l, r;
            cin >> l >> r;

            int x, y;
            x = tmp1[l - 1];
            if (r == n)
                y = 0;
            else
                y = rev[r + 1];

            cout << gcd(x, y) << endl;
        }
    }
    return 0;
}