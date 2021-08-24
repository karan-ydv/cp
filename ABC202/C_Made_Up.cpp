#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int a[n], b[n], c[n];
    map<int, int> mp1, mp2, mp3;
    map<int, vector<int>> mp;
    for(int &x: a)  cin >> x, mp1[x]++;
    int i = 1;
    for(int &x: b)  cin >> x, mp2[x]++, mp[x].emplace_back(i++);
    for(int &x: c)  cin >> x, mp3[x]++;

    int ans = 0;
    for(auto [x, f]: mp1)
    {
        int c = 0;
        for(int y: mp[x])
            c += mp3[y];
        ans += f * c;
    }
    cout << ans;
}