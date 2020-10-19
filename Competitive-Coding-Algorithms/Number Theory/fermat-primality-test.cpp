#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
#define INF 1e9
#define mod 1000000007

int main()
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