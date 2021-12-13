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
        int n, m;   cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        
        for(int i = 0; i < n; i++)
        for(int &x: v[i]) cin >> x;
        sort(v.begin(), v.begin() + n);
        
        int pref[n][m];
        for(int i = 0; i < n; i++)
        {
            pref[i][0] = v[i][0];
            for(int j = 1; j < m; j++)
        }
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {

        }
    }
}