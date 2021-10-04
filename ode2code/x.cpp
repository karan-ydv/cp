#include <bits/stdc++.h>
using namespace std;

// typedef pair<long long, long long> pii;
// struct Stack {
//     stack<pii> items, mx;
//     Stack() { mx.push({-1, -1}); }
//     void push(pii x) {
//         items.push(x);
//         mx.push(std::max(x, mx.top()));
//     }
//     void pop() {
//         if(items.empty())   return;
//         items.pop();
//         mx.pop();
//     }
//     pii max() {
//         if(items.empty())
//             return {0, 0};
//         return mx.top();
//     }
//     pii top()       { return items.top(); }
//     bool empty()    { return items.empty(); }
//     int size()      { return items.size(); }
// };

// struct Queue {
//     Stack s1{}, s2{};
//     int N;
//     Queue(int k): N(k) {}
//     void push(pii x) {
//         s1.push(x);
//         if(s1.size() + s2.size() > N)
//             pop();
//     }
//     void pour() {
//         if(s2.empty()) {
//             while(!s1.empty()) {
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }
//     }
//     void pop() {
//         if(s2.empty())  pour();
//         if(!s2.empty())
//             s2.pop();
//     }
//     int max() {
//         return std::max(s1.max(), s2.max()).second;
//     }
// };
long long solve(int N, int K, vector<int> weight, vector<int> value)
{
    multiset<pair<long long, long long>> set;
    vector<long long> dp(N);
    set.insert({-1ll, 0ll});
    long long ans = 0;
    for(int i = N - 1; i >= 0; i--)
    {
        dp[i] = value[i] + set.rbegin()->second;;
        set.insert({weight[i], dp[i]});
        ans = max(ans, dp[i]);
        if(set.size() > K + 1)
        {
            auto itr = set.find({weight[i + K], dp[i + K]});
            set.erase(itr);
        }
    }
    return ans;
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, k;   cin >> n >> k;
        vector<int> w(n), v(n);
        for(int &x: w)   cin >> x;
        for(int &x: v)   cin >> x;
        cout << solve(n, k, w, v) << '\n';
    }
}