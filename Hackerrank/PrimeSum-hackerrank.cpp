// Armed with Goldbach’s conjecture, we now have a strategy. For

// N < 2K: The answer is “No”, because the sum of K primes is at least 2K.

// N ≥ 2K and K = 1: The answer is “Yes” if N is prime, and “No” otherwise.

// N ≥ 2K, K = 2 and N is even: The answer is “Yes” (by Goldbach’s conjecture).

// N ≥ 2K, K = 2 and N is odd: The answer is “Yes” if N − 2 is prime, and “No” otherwise. This is because the sum of two odd primes is even, and the only even prime number is 2, so one of the prime numbers in the sum must be 2.

// N ≥ 2K and K ≥ 3: The answer is “Yes”. This is because if N is even, then N − 2(K − 2) is also even, so it is the sum of two primes, say p and q (by Goldbach’s conjecture). Thus, N is the sum of the K primes 2, 2, 2, ..., p, q. And if N is odd, then N − 3 − 2(K − 3) is even, so it is the sum of two primes, say p and q. Thus, N is the sum of the K primes 3, 2, 2, ..., p, q.

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

bool isPrime(ll n)
{
    if (n <= 4)
        return n == 2 || n == 3;

    for (ll i = 0; i < 5; i++)
    {
        ll a = 2 + (rand() % (n - 3));
        ll res = power(a, n - 1, n);
        if (res != 1)
            return false;
    }
    return true;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll k, n;
        cin >> n >> k;
        if (2 * k > n)
        {
            cout << "No" << endl;
            continue;
        }
        if (k == 1)
        {
            if (isPrime(n))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            continue;
        }

        if (k == 2)
        {
            if (n % 2 == 0)
                cout << "Yes" << endl;
            else
            {
                if (isPrime(n - 2))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
            continue;
        }

        if (k >= 3)
        {
            cout << "Yes" << endl;
            continue;
        }
    }
    return 0;
}
