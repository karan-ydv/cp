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
        vector<int> a[n];
        vector<int> v;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int m;  cin >> m;
            a[i].resize(m);
            for(int &x: a[i])
                cin >> x;
            int prev = -1, sz = 0;
            deque<int> dq;
            for(int x: a[i])
            {
                if(x < prev)
                {
                    dq.push_back(sz);
                    v.push_back(sz);
                    sz = 0;
                }
                prev = x;
                sz++;
            }
            if(sz)
            {
                dq.push_back(sz);
                v.push_back(sz);
            }
            while(dq.size() > 1)
            {
                if(dq.front() < dq.back())
                {
                    ans += dq.front();
                    dq.pop_front();
                }
                else
                {
                    ans += dq.back();
                    dq.pop_back();
                }
            }
        }
        // for(int x: v) cerr << x << ' ';
        // cerr << '\n';
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int x: v) heap.push(x);
        while(heap.size() > 1)
        {
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();
            ans += a + b;
            heap.push(a + b);
        }
        cout << ans << '\n';
    }
}