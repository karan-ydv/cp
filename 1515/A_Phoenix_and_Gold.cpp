#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, x;   cin >> n >> x;
        int a[n];   for(int &x: a)  cin >> x;
        if(n == 1)
        {
            if(a[0] == x)
                cout << "NO\n";
            else
                cout << "YES\n" << a[0] << '\n';
            continue;
        }
        sort(a, a + n);
        int sum = 0;
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            sum += a[i];
            if(sum == x)
            {
                if(i == n - 1)  flag = false;
                else            swap(a[i], a[i + 1]);
                break;
            }
        }
        if(flag)
        {
            cout << "YES\n";
            for(int v: a)   cout << v << ' ';   cout << '\n';
        }
        else
        {
            cout << "NO\n";
        }
    }
}