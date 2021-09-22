#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int x[n], y[n];
    set<pair<int, int>> set;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        set.insert({x[i], y[i]});
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++)
    if(x[i] != x[j] and y[i] != y[j])
    {
        pair<int, int> a = {x[i], y[i]};
        ans += set.count({x[i], y[j]}) and set.count({x[j], y[i]});
    }
    ans /= 2;
    cout << ans;
}