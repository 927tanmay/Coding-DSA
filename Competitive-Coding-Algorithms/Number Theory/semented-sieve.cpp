#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
#define INF 1e9
#define mod 1000000007
bool isPrime[1000001];

void sieve()
{
    ll maxN = 1000000;
    for (ll i = 0; i <= maxN; i++)
        isPrime[i] = true;

    isPrime[0] = isPrime[1] = false;

    for (ll i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= maxN; j += i)
                isPrime[j] = false;
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    sieve();
    while (t--)
    {
        ll m, n;
        cin >> m >> n;
        if (m == 1)
            m++;
        bool res[n - m + 1];

        for (ll i = 0; i < n - m + 1; i++)
        {
            res[i] = true;
        }

        for (ll i = 2; i * i <= n; i++)
        {
            if (isPrime[i])
            {
                ll tmp = ceil(m / i);
                tmp = tmp * i;
                for (ll j = tmp; j <= n; j += i)
                {
                    if (i != j)
                        res[j - m] = false;
                }
            }
        }

        for (ll i = 0; i <= n - m; i++)
        {
            if (res[i])
                cout << i + m << endl;
        }
        cout << endl;
    }
    return 0;
}