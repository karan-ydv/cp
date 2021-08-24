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
        int a[n + 1];
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int k = 1; ; k++)
            {
                int j = a[i] * k - i;
                if(j > n)   break;
                if(j > i and a[j] == k)
                    ans ++;
            }
        }
        cout << ans << '\n';
    }
}