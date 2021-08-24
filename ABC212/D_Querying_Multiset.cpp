#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;  cin >> q;
    int sum = 0;
    priority_queue<int, deque<int>, greater<int>> heap;
    while(q--)
    {
        int op, x; cin >> op;
        if(op == 1)
        {
            cin >> x;
            heap.push(x - sum);
        }
        else if(op == 2)
        {
            cin >> x;
            sum += x;
        }
        else
        {
            int ans = heap.top() + sum;
            heap.pop();
            cout << ans << '\n';
        }
    }
}