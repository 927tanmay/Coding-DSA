// https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/roy-and-rangoli-1/description/
// 12 : {6,6) : 1
// 11 : {5,6} , {6,5} : 2
// 10 : {4,6} , {6,4} , {5,5} : 3
// 9 : ………. : 4
// 8 : ………. : 5
// 7 : ………. : 6
// 6 : ………. : 7
// 5 : ………. : 6
// 4 : ………. : 5
// 3 : ………. : 4
// 2 : {0,2} , {2,0} , {1,1} : 3
// 1 : {0,1} , {1,0} : 2
// 0 : {0,0} : 1

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define REP(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
#define INF 1e9
#define mod 1000000007
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
bool isPrime[2000002];

void sieve()
{
    int maxN = 2000001;
    for (ll i = 2; i <= maxN; i++)
        isPrime[i] = true;

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
    fast

    sieve();

    ll n, c = 0;
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        if (isPrime[i])
            c = (c + i + 1) % mod;
    }
    for (ll i = n; i < 2 * n - 1; i++)
    {
        if (isPrime[i])
            c = (c + 2 * (n - 1) - i + 1) % mod;
    }
    cout << c << endl;

    return 0;
}