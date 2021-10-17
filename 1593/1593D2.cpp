#include <bits/stdc++.h>
using namespace std;
int solve()
{
    int n;	cin >> n;
    int a[n]; for(int &x: a)    cin >> x;

    int mn = *min_element(a, a + n);
    for(int &x: a)  x -= mn;
    int mx = *max_element(a, a + n);

    unordered_map<int, int> mp;
    for(int x: a)   mp[x]++;
    for(auto [x, f]: mp)
        if(2 * f >= n)  return -1;

    for(int k = mx; k > 1; k--)
    {
        unordered_map<int, int> mp2;
        for(auto [x, f]: mp) {
            int y = x % k;
            mp2[y] += f;
            if((mp2[y] << 1) >= n)
                return k;
        }
    }
    return 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        cout << solve() << '\n';
    }
}