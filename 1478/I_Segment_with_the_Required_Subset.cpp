#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1001;
int n, k;

struct Stack1 {
    stack<bitset<N>> s;
    stack<int> items;
	Stack1()
	{
	    bitset<N> b;
	    b[0] = 1;
	    s.push(b);
	}
    void push(int x)
    {
        items.push(x);
		bitset<N> b = s.top();
		b |= b << x;
		s.push(b);
    }
    void pop() {
        if(items.empty()) return;
		s.pop(); items.pop();
    }
    int top()       { return items.top(); }
    bool empty()    { return items.empty(); }
};
struct Stack2 {
    stack<bitset<N>> s;
	Stack2()
	{
	    bitset<N> b;
	    b[k] = 1;
	    s.push(b);
	}
    void push(int x)
    {
		bitset<N> b = s.top();
		b |= b >> x;
		s.push(b);
    }
    bool pop() {
		if(s.size() == 1)
			return false;
		return s.pop(), true;
	}
};
struct Queue {
    Stack1 s1;	Stack2 s2;
    void push(int x) { s1.push(x); }
    void pop() {
        if(!s2.pop())
		{
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
			s2.pop();
        }
    }
    bool good() {
        return (s1.s.top() & s2.s.top()).count();
    }
};


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    
    Queue q;
    
    int ans = 1 << 30, x, L = -1;
    for(int R = 0; R < n; R++)
    {
        cin >> x;    q.push(x);
        while(q.good())
        {
            ans = min(ans, R - L);
            q.pop();
            ++L;
        }
    }
    if(ans == 1 << 30)
        ans = -1;
    cout << ans;
}