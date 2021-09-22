/* compile with 
g++ B_Traffic_Control.cpp -O2 -std=c++17 -Wl,--stack=268435456
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int x = n + m - 2;
        if(a <= x or b <= x) {
            cout << "Impossible\n";
            continue;
        }
        cout << "Possible\n";
        vector<vector<int>> g(n, vector<int>(m, 1));
        g[0][0] = a - x;
        g[0][m - 1] = b - x;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cout << g[i][j] << " \n"[j == m - 1];
    }
}