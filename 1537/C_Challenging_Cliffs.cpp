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
        int a[n];   for(int &x: a)  cin >> x;
        sort(a, a + n);
        
        if(n == 2)
        {
            cout << a[0] << ' ' << a[1] << '\n';
            continue;
        }

        int mn = 2e9;
        for(int i = 1; i < n; i++)
        if(a[i] - a[i - 1] < mn)
        {
            mn = a[i] - a[i - 1];
        }
        int idx, mx = -1;
        for(int i = 1; i < n; i++) if(a[i] - a[i - 1] == mn)
        {
            int cnt = n - 2 + (a[0] >= a[n - 1]);
            if(cnt > mx)
            {
                mx = cnt;
                idx = i;
            }
        }
        for(int i = idx; i < n; i++)    cout << a[i] << ' ';
        for(int i = 0; i < idx; i++)    cout << a[i] << ' ';
        cout << '\n';
    }
}