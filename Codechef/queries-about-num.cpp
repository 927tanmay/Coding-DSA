// Here T is the type of query and K is the natural number.
// If T=1, Chef must find the number of natural numbers which is divisor of both N and K.
// If T=2, Chef must find the number of natural numbers which is divisor of N and is divisible by K.
// If T=3, Chef must find the number of natural numbers which is divisor of N and is not divisible by K.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
#define INF 1e9
#define mod 1000000007

map<ll, ll> m;

ll min(ll a, ll b)
{
    if (a < b)
        return a;
    else
        return b;
}

ll total;
void factorize(ll n)
{
    total = 1;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n = n / i;
                m[i]++;
            }
            total *= m[i] + 1;
        }
    }

    if (n > 1)
    {
        m[n]++;
        total *= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, q;
    cin >> n >> q;
    factorize(n);
    while (q--)
    {
        ll t, k;
        cin >> t >> k;

        switch (t)
        {
        case 1:
        {
            ll res = 1;
            for (auto itr : m)
            {
                ll c = 0;
                while (k % itr.first == 0)
                {
                    k = k / itr.first;
                    c++;
                }
                res *= min(c, itr.second) + 1;
            }
            cout << res << endl;
            break;
        }
        case 2:
        {
            ll res = 1;
            ll x = n / k;

            for (auto itr : m)
            {
                ll c = 0;
                while (k % itr.first == 0)
                {
                    k = k / itr.first;
                    c++;
                }
                if (c > itr.second)
                {
                    res = 0;
                    break;
                }
                res *= (itr.second - c) + 1;
            }

            if (k > 1)
                res = 0;
            cout << res << endl;
            break;
        }
        case 3:
        {
            ll res = 1;
            ll x = n / k;
            //   if(x!=0){
            for (auto itr : m)
            {
                ll c = 0;
                while (k % itr.first == 0)
                {
                    k = k / itr.first;
                    c++;
                }
                if (c > itr.second)
                {
                    res = 0;
                    break;
                }
                res *= (itr.second - c) + 1;
            }

            if (k > 1)
                res = 0;
            cout << total - res << endl;
            break;
        }
        }
    }
    return 0;
}

// Second Approach

//   case 2: {ll res=1;
//              ll x=n/k;
//                 if(n%k==0){
//                 for(auto itr:m){
//                 ll c=0;
//                 if(x==0){
//                     res=0;
//                     break;
//                 }

//                 while(x%itr.first==0){
//                     x=x/itr.first;
//                     c++;
//                 }

//                 res*= c+1;

//              }}
//              else
//              res=0;

//             cout<<res<<endl;
//             break;}