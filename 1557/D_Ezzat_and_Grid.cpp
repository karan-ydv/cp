#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 3e5 + 69;
vector<pair<int, int>> a[N];
int dp[N];

bool overlap(pair<int, int> &a, pair<int, int> &b) {
    if (a.second + 1 < b.first)
        return false;
    a = b = {a.first, max(a.second, b.second)};
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, l, r;    cin >> x >> l >> r;
        a[x].emplace_back(l, r);
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++)
    {
        sort(a[i].begin(), a[i].end());
        for(int j = 0; j + 1 < a[i].size(); j++)
        {
            int k;
            for(k = j; k + 1 < a[i].size(); k++)
                if(!overlap(a[i][k], a[i][k + 1]))
                    break;
            for(int x = j; x < k; x++)
                a[i][x] = a[i][k];
        }
        a[i].resize(unique(a[i].begin(), a[i].end()) - a[i].begin());
        if(a[i].size() == 0)
            ans.emplace_back(i);
        // cerr << i << " : ";
        // for(auto [l, r]: a[i])
        //     cerr << l << ' ' << r << ' ';
        // cerr << '\n';
    }
}