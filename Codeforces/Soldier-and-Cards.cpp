// Problem Link: http://codeforces.com/contest/546/problem/C

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
        ll n,
        k1, k2, x;
    cin >> n;
    queue<int> q1, q2, chk1, chk2;
    cin >> k1;

    for (int i = 0; i < k1; i++)
    {
        cin >> x;
        q1.push(x);
        chk1.push(x);
    }

    cin >> k2;

    for (int i = 0; i < k2; i++)
    {
        cin >> x;
        q2.push(x);
        chk2.push(x);
    }
    ll count = 0;
    while (!q1.empty() && !q2.empty())
    {
        int t1 = q1.front();
        int t2 = q2.front();
        q1.pop();
        q2.pop();

        if (t1 > t2)
        {
            q1.push(t2);
            q1.push(t1);
        }
        else
        {
            q2.push(t1);
            q2.push(t2);
        }
        count++;
        if (count > 1e6)
        {
            count = -1;
            cout << count << " ";
            return 0;
        }
    }

    cout << count << " ";
    if (!q1.empty())
        cout << 1;
    else
        cout << 2;

    return 0;
}