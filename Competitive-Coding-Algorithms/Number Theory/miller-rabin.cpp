#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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

ll power(ll a, ll n, ll modc)
{
    ll res = 1;
    a = a % modc;
    while (n)
    {
        if (n % 2 == 1)
        {
            res = ((res % modc) * (a % modc)) % modc;
            n--;
        }
        a = ((a % modc) * (a % modc)) % modc;
        n = n / 2;
    }
    return res % modc;
}

bool isComposite(ll a, ll n, ll d, ll s)
{
    ll x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int i = 1; i < s; i++)
    {
        x = (x * x) % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

int main()
{
    fast
        ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        if (n < 2)
        {
            cout << "composite" << endl;
            continue;
        }
        ll d = n - 1, s = 0;
        while ((d & 1) == 0)
        {
            d >>= 1;
            s++;
        }
        int flag = 1;

        int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        for (int i = 0; i < 12; i++)
        {
            if (arr[i] == n)
                break;

            if (isComposite(arr[i], n, d, s))
            {
                cout << "composite" << endl;
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "prime" << endl;
    }
    return 0;
}