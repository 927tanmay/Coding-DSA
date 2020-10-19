// King has just won a bet with Saitama (which everyone already knew he would). So as per the rules of the bet Saitama is going to give King  times the amount King bet, where  is the number of factors of the amount King bet.
// If King had  units of money before the bet then what is the maximum money he can have after the bet?
// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/bet-2/
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

ll fact[1000001];
ll v[1000001];
void factorise()
{
    ll maxN = 1000000;
    for (ll i = 0; i <= maxN; i++)
        fact[i] = -1;
    fact[1] = 1;
    for (ll i = 2; i <= maxN; i++)
    {
        if (fact[i] == -1)
        {
            for (ll j = i; j <= maxN; j += i)
            {
                if (fact[j] == -1)
                    fact[j] = i;
            }
        }
    }

    for (ll i = 1; i <= maxN; i++)
    {
        ll x = i, c = 0, tmp2 = fact[i], res = 1;
        while (x > 1)
        {
            x = x / fact[x];
            c++;

            if (tmp2 != fact[x])
            {
                res *= c + 1;
                c = 0;
                tmp2 = fact[x];
            }
        }

        v[i] = res;
    }
    ll cut = 1, chk = 1;
    for (ll i = 1; i <= maxN; i++)
    {
        v[i] *= i;
    }
    for (ll i = 1; i <= maxN; i++)
    {
        if (v[i] > chk)
        {
            chk = v[i];
            cut = i;
        }
        v[i] = chk + i - cut;
    }
}

int main()
{
    fast
        ll t;
    cin >> t;
    factorise();

    while (t--)
    {
        ll n;
        cin >> n;

        cout << v[n] << endl;
    }
    return 0;
}