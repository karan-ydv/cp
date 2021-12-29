#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 404;
string s[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, m;   cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> s[i]; s[i] = "!" + s[i];
        }
        
        int ans = 16;
        for(int i = 1; i <= n; i++)
        {
            int zeroes[m + 1]{}, ones[m + 1]{}, suff[m + 1]{};
            for(int j = i + 1; j <= n; j++)
            {
                if(j - i > 3) {
                    for(int k = 1; k <= m; k++)
                        suff[k] = suff[k - 1] + ones[k] + (s[i][k] == '0') + (s[j][k] == '0');                
                    
                    suff[m] = suff[m - 1] + zeroes[m];
                    for(int k = m - 3; k >= 1; k--) {
                        suff[k + 2] = suff[k + 1] + zeroes[k + 2];
                        suff[k + 2] = min(suff[k + 2], suff[k + 3]);
                        ans = min(ans, suff[k + 3] - suff[k] + zeroes[k]);
                    }
                }
                for(int k = 1; k <= m; k++)
                    ones[k] += s[j][k] == '1', zeroes[k] += s[j][k] == '0';
            }
        }
        cout << ans << '\n';
    }
}