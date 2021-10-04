#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> n;
    // int x[n], y[n];
    // for(int i = 0; i < n; i++)  cin >> x[i];
    // for(int i = 0; i < n; i++)  cin >> y[i];
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        int x, y;   cin >> x >> y;
        mp[x].emplace_back(y);
    }
}