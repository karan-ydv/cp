#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Stack {
    stack<int> items, mx, mn;
    Stack() {
        mx.push(-1e18);
        mn.push(1e18);
    }
    void push(int x) {
        items.push(x);
        mx.push(std::max(mx.top(), x));
        mn.push(std::min(mn.top(), x));
    }
    int top() { return items.top(); }
    void pop() {
        assert(!items.empty());
        items.pop();
        mx.pop();
        mn.pop();
    }
    int max() { return mx.top(); }
    int min() { return mn.top(); }
    bool empty() { return items.empty(); }
    size_t size() { return items.size(); }
};

int32_t main() {
    Stack s = Stack();
    // cout << s.size() << ' ' << s.max() << ' ' << s.min() << '\n';
    s.push(1);
    cout << s.size() << ' ' << s.max() << ' ' << s.min() << '\n';
    s.push(2);
    cout << s.size() << ' ' << s.max() << ' ' << s.min() << '\n';
    s.pop();
    cout << s.size() << ' ' << s.max() << ' ' << s.min() << '\n';
    // s.pop();
    cout << s.size() << ' ' << s.max() << ' ' << s.min() << '\n';
}