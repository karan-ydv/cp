#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    vector<int> a[m];
    queue<pair<int, int>> q;
    map<int, int> mp;
    for(int i = 0; i < m; i++)
    {
        int k;  cin >> k;
        a[i].resize(k);
        for(int &x: a[i])   cin >> x;
        int x = a[i].back();
        if(mp.count(x))
            q.push({mp[x], i});
        else
            mp[x] = i;
    }
    int c = 0;
    while(!q.empty())
    {
        c++;
        auto [i, j] = q.front();
        q.pop();
        
        a[i].pop_back();
        a[j].pop_back();
        
        if(!a[i].empty())
        {
            int x = a[i].back();
            if(mp.count(x))
                q.push({mp[x], i});
            else
                mp[x] = i;
        }
        if(!a[j].empty())
        {
            int x = a[j].back();
            if(mp.count(x))
                q.push({mp[x], j});
            else
                mp[x] = j;
        }
    }
    if(c == n)
        cout << "Yes";
    else
        cout << "No";
}