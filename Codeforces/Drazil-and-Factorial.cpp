// Problem link: http://codeforces.com/contest/515/problem/C

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

    string a;
    cin >> a;
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == '4')
        {
            res.push_back(3);
            res.push_back(2);
            res.push_back(2);
        }
        else if (a[i] == '6')
        {
            res.push_back(5);
            res.push_back(3);
        }
        else if (a[i] == '8')
        {
            res.push_back(7);
            res.push_back(2);
            res.push_back(2);
            res.push_back(2);
        }
        else if (a[i] == '9')
        {
            res.push_back(3);
            res.push_back(3);
            res.push_back(2);
            res.push_back(7);
        }
        else if (a[i] != '1' && a[i] != '0')
            res.push_back(a[i] - '0');
    }
    sort(res.begin(), res.end());
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];

    return 0;
}