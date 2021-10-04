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
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            string s;   cin >> s;
            for(int j = 0; j < m; j++)
                if(s[j] == '1') v.emplace_back(i + j, i - j);
        }
        sort()
    }
}

