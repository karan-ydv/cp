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
        int a[n];
        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]].emplace_back(i);
        }
        int sum = 0, ans = -1e18;
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            sum = a[i];
            for(int x: mp[a[i]]) q.push(x);
            ans = max(ans, sum * (int)q.size());
            for(int j = i + 1; j < n; j++)
            {
                sum += a[j];
                queue<int> temp;
                while(!q.empty())
                {
                    int f = q.front();
                    q.pop();
                    if(f + j - i < n and a[f + j - i] == a[j])
                        temp.push(f);
                }
                q.swap(temp);
                ans = max(ans, sum * (int)q.size());
            }
            q = queue<int>();
        }
        cout << ans << '\n';
    }
}