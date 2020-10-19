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

int main()
{
    fast
        ll t;
    cin >> t;

    while (t--)
    {
        ll n, i;
        cin >> n >> i;
        ll tmp = 1;
        tmp = tmp << i;
        ll res = tmp & n;
        if (res == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}