#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
#define INF 1e9
#define mod 1000000007

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

ll power(ll a, ll n, ll m)
{
    ll res = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            res = mulmod(a % m, res % m, m);
            n--;
        }
        a = mulmod(a % m, a % m, m);
        n = n / 2;
    }
    return res % m;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        int flag = 1;

        if (n <= 4)
        {
            if (n == 2 || n == 3)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }

        for (int i = 0; i < 5; i++)
        {
            ll a = 2 + (rand() % (n - 3));
            // cout<<a<<" ";
            ll res = power(a, n - 1, n);
            if (res != 1)
            {
                cout << "NO" << endl;
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
    }
    return 0;
}