#include <bits/stdc++.h>
using namespace std;

int solve()
{
    map<int, int> mp;
    int n;	cin >> n; int a[n];
    for(int &x: a)
        cin >> x, mp[x]++;
    for(auto [x, f]: mp)
        if(2 * f >= n)  return -1;

    int ans = 1;
    for(auto [x, f]: mp)
    {
        map<int, int> count;
        clog << x << " : ";
        for(auto [y, g]: mp) if(y > x)
        {
            int m = y - x;
            clog << m << " : ";
            int s = (int) sqrt(m);
            for(int i = 1; i <= s; i++)
            if(m % i == 0)
            {
                clog << i << ' ' << m / i << ' ';
                count[i] += g;
                if(i * i != m) count[m/i] += g;
            }
            clog << ',';
        }
        clog << '\n';
        for(auto [z, h]: count) 
            if(2 * (f + h) >= n)
                ans = max(ans, z);
    }
    return ans;
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