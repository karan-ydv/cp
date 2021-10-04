#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int a[n];   for(int &x: a)  cin >> x;
    int m;  cin >> m;
    int b[m];   for(int &x: b)  cin >> x;
    unordered_map<int, int> mp, mp2;
    for(int x: b)   mp[x]++;
    m--;
    for(int i = 0; i < m; i++) {
        mp[a[i]]--;
        if(mp[a[i]] == 0)   mp.erase(a[i]);
    }
    vector<int> ans;
    if(mp.size() == 1)
        ans.emplace_back(1);
    for(int i = m; i < n; i++) {
        mp[a[i]]--;
        if(mp[a[i]] == 0)   mp.erase(a[i]);
        mp[a[i - m]]++;
        if(mp[a[i - m]] == 0)   mp.erase(a[i - m]);
        if(mp.size() == 1)
            ans.emplace_back(i - m + 2);
    }
    for(int x: ans) cout << x << ' ';
}
