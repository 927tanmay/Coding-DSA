// Hence after all the digits are calculated, below algorithm is followed:

// Initialize the first digit to ans.
// Iterate for all n-1 digits.
// Compute ans at every ith step by (ans * 10 + digit[i]) % 41 using associative property.
// Check for the final value of ans if it divisible by 41 r not.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
#define INF 1e9
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;

    while (t--)
    {
        ll a0, a1, c, n;
        cin >> a0 >> a1 >> c >> n;
        ll num[n];
        if (n < 2)
        {
            if (a0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
            continue;
        }

        num[0] = a0;
        num[1] = a1;
        ll res = (num[0] * 10 + num[1]) % 41;
        for (ll i = 2; i < n; i++)
        {
            num[i] = (num[i - 1] * c + num[i - 2]) % 10;
            res = (res * 10 + num[i]) % 41;
        }

        if (res % 41 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}