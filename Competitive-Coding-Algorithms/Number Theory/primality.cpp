#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, flag = 0;
        cin >> n;
        if (n == 1)
        {
            cout << "no" << endl;
            continue;
        }

        for (int i = 2; i*i <= n; i++)
        {
            if (n % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}