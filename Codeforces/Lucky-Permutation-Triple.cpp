// Problem Link : http://codeforces.com/contest/304/problem/C

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
        ll n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << -1;
        return 0;
    }

    REP(i, n)
        cout << i << " ";
    cout << endl;
    REP(i, n)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << (i + i) % n << " ";
    }

    return 0;
}