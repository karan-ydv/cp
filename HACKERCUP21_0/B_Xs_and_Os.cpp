/* compile with 
g++ B_Xs_and_Os.cpp -O2 -std=c++17 -Wl,--stack=268435456
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 1; _ <= t; _++)
    {
        cout << "Case #" << _ << ": ";
        int n;
        cin >> n;
        string s[n];
        for (auto &x : s)
            cin >> x;
        
        set<vector<int>> set;   

        int ans = 1e9, cnt = 0;
        for (int i = 0, j; i < n; i++)
        {
            vector<int> v;
            auto f = [&]()
            {
                if (j == n)
                {
                    if (v.size() < ans)
                        ans = v.size(), set = {v};
                    else if (v.size() == ans)
                        set.insert(v);
                }
            };
            for (j = 0; j < n; j++)
            {
                if (s[i][j] == 'O')
                    break;
                if (s[i][j] == '.')
                    v.emplace_back(i * n + j);
            }
            f();
            for (j = 0, v = {}; j < n; j++)
            {
                if (s[j][i] == 'O')
                    break;
                if (s[j][i] == '.')
                    v.emplace_back(j * n + i);
            }
            f();
        }
        if (ans == 1e9)
            cout << "Impossible\n";
        else
            cout << ans << ' ' << set.size() << '\n';
    }
}