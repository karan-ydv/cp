#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 1; i <= n; i++) if(s[i] == '1')
    for(int j = i; j <= n; j++) if(s[j] == '2')
    for(int k = j; k <= n; k++) if(s[k] == '3') ans++;
    cout << ans;
}