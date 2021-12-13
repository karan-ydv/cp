#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;

int n;
int dfs(int h = 1)
{
    if(h == n)
        return 1;
    
    int d = dfs(h + 1);
    return (d * d % mod * 16) % mod;

}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int ans = dfs(1) * 6 % mod;
    cout << ans;    
}