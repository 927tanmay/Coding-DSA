// Problem Link : https://codeforces.com/contest/437/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, sum, i;
    cin >> sum >> n;
    ll a[n + 1];
    for (i = 1; i <= n; i++)
    {
        a[i] = i & ~(i - 1);
    }
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        ans += a[i];
    }
    if (sum > ans)
    {
        cout << "-1" << endl;
        return 0;
    }
    vector<pair<ll, ll>> b;
    for (i = 1; i <= n; i++)
    {
        b.push_back({a[i], i});
    }
    sort(b.begin(), b.end());
    vector<ll> v;
    for (i = b.size() - 1; i >= 0; i--)
    {
        if (sum == 0)
            break;
        if (sum < b[i].first)
            continue;
        else
        {
            sum -= b[i].first;
            v.push_back(b[i].second);
        }
    }
    cout << v.size() << endl;
    for (i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    return 0;
}
