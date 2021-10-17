#include <bits/stdc++.h>
using namespace std;

const int K = 1e6+5;
int best[K], b[5005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        int n, k;   cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> b[i];
        fill_n(best + 1, k, 1e9);

        int ans = 1e9;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i, sum = 0; j <= n and (sum += b[j]) <= k; j++)
                ans = min(ans, best[k - sum] + j - i + 1);
            for(int j = i, sum = 0; j >= 1 and (sum += b[j]) <= k; j--)
                best[sum] = min(best[sum], i - j + 1);
        }

        if(ans == 1e9)  ans = -1;
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}