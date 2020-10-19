// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/too-much-to-count-fb914aed/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
#define INF 1e9
#define mod 1000000007

ll sieve[1000001];

void factorise()
{
    ll maxN = 1000000;
    for (ll i = 0; i <= maxN; i++)
        sieve[i] = -1;

    sieve[0] = sieve[1] = -1;

    for (ll i = 2; i <= maxN; i++)
    {
        if (sieve[i] == -1)
        {
            for (ll j = i; j <= maxN; j += i)
            {
                if (sieve[j] == -1)
                    sieve[j] = i;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    factorise();
    while (t--)
    {
        ll n;
        cin >> n;

        ll res = n, count = 1, x = n;

        while (n > 1)
        {
            res /= sieve[n];
            res *= sieve[n] - 1;
            ll tmp = sieve[n];
            int c = 0;
            while (n > 1 && tmp == sieve[n])
            {
                n = n / sieve[n];
                c++;
            }
            count *= c + 1;
        }

        cout << x - count - res + 1 << endl;
    }
    return 0;
}