#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
int dp[N], pre[N];
vector<int> g[N];

// dp[v] = minimum jumps to reach 0 if frog jums to v and slips down
// g[i] = list of heights from which frog slips down to i

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n;
    fill_n(dp, n + 1, 1e9);
    fill_n(pre, n + 1, -1);

    typedef pair<int, int> pii;
    priority_queue<pii, deque<pii>, greater<pii>> heap; // min heap
    for(int i = 1; i <= n; i++) {
        int x;  cin >> x;
        heap.push({i - x, i});
    }
    for(int i = 1; i <= n; i++) {
        int x;  cin >> x;
        g[i + x].push_back(i);
    }

    queue<int> q;
    q.push(0);
    dp[0] = 0;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        while(!heap.empty())
        {
            auto [x, u] = heap.top();
            if(x > v)    break; // can't jump upto v from u
            // u = index from which frog can jump highest
            for(int j: g[u]) // frog slips down to u from j
            if(dp[j] > dp[v] + 1)
            {
                dp[j] = dp[v] + 1;
                pre[j] = v;
                q.push(j);
            }
            heap.pop();
        }
    }

    if(dp[n] == 1e9) dp[n] = -1;

    cout << dp[n] << '\n';
    while(pre[n] != -1)
    {
        n = pre[n];
        cout << n << ' ';
    }
}