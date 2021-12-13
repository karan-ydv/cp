#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Stack {
    stack<int> items, mx, mn;
    void push(int x) {
        items.push(x);
        if(mx.empty() or mx.top() <= x)   mx.push(x);
        if(mn.empty() or mn.top() >= x)   mn.push(x);
    }
    int top() {
        return items.top();
    }
    void pop() {
        if(items.empty())   return;
        int x = items.top();
        items.pop();
        if(x == mx.top())   mx.pop();
        if(x == mn.top())   mn.pop();
    }
    int max() {
        if(items.empty())
            return 0;
        return mx.top();
    }
    int min() {
        if(items.empty())
            return 1e18;
        return mn.top();
    }
    bool empty() {
        return items.empty();
    }
};
struct Queue {
    Stack s1, s2;
    void push(int x) {
        s1.push(x);
    }
    void pour() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    int front() {
        if(s2.empty())  pour();
        if(s2.empty())  return 0;
        return s2.top();
    }
    void pop() {
        if(s2.empty())  pour();
        if(!s2.empty())
            s2.pop();
    }
    int max() {
        return std::max(s1.max(), s2.max());
    }
    int min() {
        return std::min(s1.min(), s2.min());
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, s;   cin >> n >> s;
        int a[n + 1]{};
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        partial_sum(a, a + n + 1, a);
        auto fun = [&](int m) {
            Queue q;
            for(int i = 1; i < m; i++)
                q.push(a[i]);
            for(int i = m; i <= n; i++) {
                q.push(a[i]);
                int mn = q.min();
                if(s + mn >= a[i - m])
                    return i - m + 1;
                q.pop();
            }
            return -1LL;
        };
        int beg = 1, end = n, ans = -1, L;
        while(beg <= end)
        {
            int mid = (beg + end) >> 1;
            int x = fun(mid);
            if(x == -1)
                end = mid - 1;
            else
                beg = mid + 1, ans = mid, L = x;
        }
        if(ans == -1)
            cout << "-1\n";
        else
            cout << L << ' ' << L + ans - 1 << '\n';
    }
}