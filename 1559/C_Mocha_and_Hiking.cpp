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
        int n;	cin >> n;
        int a[n + 2];
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        a[n + 1] = 1;
        int p = -1;
        for(int i = 1; i <= n; i++)
        if(a[i] == 0 and a[i + 1] == 1)
        {
            p = i;
            break;
        }
        if(p == -1)
        {
            cout << n + 1 << ' ';
            for(int j = 1; j <= n; j++)
                cout << j << ' ';
        }
        else
        {
            for(int i = 1; i <= p; i++) cout << i << ' ';
            cout << n + 1 << ' ';
            for(int i = p + 1; i <= n; i++) cout << i << ' ';
        }
        cout << '\n';
    }
}