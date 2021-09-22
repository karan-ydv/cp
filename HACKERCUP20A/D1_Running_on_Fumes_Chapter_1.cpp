#include <bits/stdc++.h>
#define int int64_t
using namespace std;

// const int inf = 1e18;
const int inf = 1ll << 60;
struct Stack {
    stack<int> items, mx, mn;
    Stack() {
        mx.push(-inf);
        mn.push(inf);
    }
    void push(int x) {
        items.push(x);
        mx.push(std::max(mx.top(), x));
        mn.push(std::min(mn.top(), x));
    }
    int top() { return items.top(); }
    void pop() {
        int x = items.top();
        items.pop();
        mx.pop();
        mn.pop();
    }
    int max() { return mx.top(); }
    int min() { return mn.top(); }
    bool empty() { return items.empty(); }
    size_t size() { return items.size(); }
};
struct Queue {
    Stack s1, s2;
    void push(int x) { s1.push(x); }
    void pour() {
        assert(s2.empty());
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int front() {
        if(s2.empty())  pour();
        assert(!s2.empty());
        return s2.top();
    }
    void pop() {
        if(s2.empty())  pour();
        assert(!s2.empty());
        s2.pop();
    }
    int max() { return std::max(s1.max(), s2.max()); }
    int min() { return std::min(s1.min(), s2.min()); }
    size_t size() { return s1.size() + s2.size(); }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        int n, m;   cin >> n >> m;
        int c[n];   
        for(int &x: c) {
            cin >> x;
            if(x == 0)
                x = inf;
        }
        Queue q;
        q.push(0);
        for(int i = 1; i < n - 1; i++) {
            q.push(min(q.min() + c[i], inf));
            if(q.size() > m)   q.pop();
        }
        int ans = q.min();
        if(ans == inf)
            ans = -1;
        cout << ans << '\n';
    }
}