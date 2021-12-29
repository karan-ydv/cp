#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    int a[m];   for(int &x: a)  cin >> x;

    map<pair<int, int>, int> mp;
    for(int i = 1; i < m; i++) {
        int x = a[i], y = a[i - 1];
        if(x > y) swap(x, y);
        mp[{x, y}]++;
    }
    
    cout << ans << ' ';
    for(int i = 2; i <= n; i++)
    {

    }
}