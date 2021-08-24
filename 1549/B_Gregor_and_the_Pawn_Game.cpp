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
        string a, b;
        int n;	cin >> n >> a >> b;
        int ans = 0;
        for(int i = 0; i < n;  i++)
        if(b[i] == '1')
        {
            if(a[i] == '0')
                ans++;
            else
            {
                if(i > 0 and a[i - 1] == '1')
                    ans++;
                else if(i + 1 < n and a[i + 1] == '1')
                {
                    ans ++;
                    a[i + 1] = '!';
                }
            }
        }
        cout << ans << '\n';
    }
}