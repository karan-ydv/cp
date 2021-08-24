#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<int, int> solve(int n, int b)
{
    list<int> q;
    int cnt = 0, last;
    while(n--)
    {
        int t, d;
        cin >> t >> d;
        while(!q.empty())
        {
            if(q.front() <= t)
                q.pop_front();
            else
                break;
        }
        if(q.size() > b)
        {
            cnt += 1;
            continue;
        }
        if(!q.empty())
            t = q.back();
        q.push_back(t + d);
        last = q.back();
    }   
    return {cnt, q.back()};
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, b;   cin >> n >> b;
    auto [x, y] = solve(n, b);
    cout << x << ' ' << y;
}