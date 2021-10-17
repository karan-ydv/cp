#include <bits/stdc++.h>
using namespace std;

int correlative(vector<int> &v, int k) {
    int ans = 0;
    map<int, int> mp;
    for(int x: v)
    {
        x = (x % k + k) % k;
        ans = max(ans, ++mp[x]);
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;  cin >> t;
    while(t--)
    {
        int n, k;   cin >> n >> k;
        vector<int> v(n);
        for(int &x: v)  cin >> x;
        cout << correlative(v, k);
    }
}