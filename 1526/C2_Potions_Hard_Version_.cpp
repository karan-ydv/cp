#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    priority_queue<int, deque<int>, greater<int>> pq;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int x;  cin >> x;
        if(sum + x >= 0)
        {
            sum += x;
            pq.push(x);
        }
        else if(pq.top() < x)
        {
            sum -= pq.top();
            pq.pop();
            pq.push(x);
            sum += x;
        }
    }
    cout << pq.size();
}