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
        // int a[n]; for(int &x: a) cin >> x;
        deque<int> ans, p;
        for(int i = 0; i < n; i++) {
            int x;  cin >> x;
            p.push_back(x);
        }
        if(p.back() != n and p.front() != n) {
            cout << "-1\n";
            continue;
        }
        while(!p.empty())
        {
            if(p.front() > p.back()) {
                ans.push_front(p.front());
                p.pop_front();
            }
            else {
                ans.push_back(p.back());
                p.pop_back();
            }
        }
        for(int x: ans) cout << x << ' ';
        cout << '\n';
    }
}