#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[n];   for(int &x: a)  cin >> x;
        priority_queue<pair<int, int>> heap;
        vector<pair<int, int>> ans;
        for(int i = 0; i < n; i++) {
            if(a[i]) heap.push({a[i], i + 1});
        }
        while(heap.size() > 1)
        {
            auto [s1, x] = heap.top(); heap.pop();
            auto [s2, y] = heap.top(); heap.pop();
            ans.emplace_back(x, y);
            if(--s1)    heap.push({s1, x});
            if(--s2)    heap.push({s2, y});
        }
        cout << ans.size() << '\n';
        for(auto [x, y]: ans)
            cout << x << ' ' << y << '\n';
    }
}