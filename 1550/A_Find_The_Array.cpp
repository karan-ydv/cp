#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 5000 + 69;
int dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int ans = 0;
        for(int i = 1; n; i += 2)
        {
            if(n < i)
            {
                ans += 1;
                break;
            }
            n -= i;
            ans ++;
        }
        cout << ans << '\n';
    }
}