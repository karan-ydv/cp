#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+69;
bool dp[N][N];
int a[N], ans[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, d;
    cin >> n >> m >> d;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    
    dp[0][0] = 1;
    vector<int> pref(n + 2);
    for(int i = a[1]; i <= min(n, d + a[1] - 1); i++)
        pref[i] = dp[1][i] = 1;
    
    for(int i = 1; i <= n; i++)
        pref[i] += pref[i - 1];
    
    for(int i = 2; i <= m; i++)
    {
        vector<int> v(n + 2);
        for(int j = a[i]; j <= n; j++)
        {
            int l = max(0, j - a[i] - d);
            int r = j - a[i];
            dp[i][j] = pref[r] - pref[l];
            v[j] = (int) dp[i][j];            
        }
        v.swap(pref);
        for(int j = 1; j <= n; j++)
            pref[j] += pref[j - 1];
    }

    bool flag = false;
    for(int i = max(1, n - d + 1); i <= n; i++)
        flag |= dp[m][i];
    if(!flag)
        return cout << "NO", false;
    cout << "YES\n";
    for(int i = m, j = n; i >= 1; i--)
    {
        while(!dp[i][j]) j--;
        for(int k = j - a[i] + 1; k <= j; k++)
            ans[k] = i;
        j -= a[i];
    }
    for(int i = 1; i <= n; i++) 
        cout << ans[i] << ' ';
}