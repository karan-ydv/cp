#include <bits/stdc++.h>
#define int long long
using namespace std;


struct Stack {
    stack<int> items, mx, mn;
    Stack()
    {
    	mx.push(0);
    	mn.push(1e18);
    }
    void push(int x)
    {
        items.push(x);
        mx.push(std::max(mx.top(), x));
        mn.push(std::min(mn.top(), x));
    }
    void pop()
    {
        if(items.empty())   return;
        items.pop();
        mx.pop();
        mn.pop();
    }
    int top()		{ return items.top(); }
    int max()		{ return mx.top(); }
    int min()		{ return mn.top(); }
    bool empty()	{ return items.empty(); }
};
 
struct Queue {
    Stack s1, s2;
    void push(int x) { s1.push(x); }
    void pour()
    {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    int front()
    {
        if(s2.empty())  pour();
        if(s2.empty())  return -1;
        return s2.top();
    }
    void pop()
    {
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
} q;

const int N = 5e5 + 1;
int L, R, A[N];
void add(int x) {

}
void remove(int x) {

}

bool good() {
	if(q.size() < )
	return q.max() >= max(A[L], A[R]);
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;	cin >> n;
	int a[n + 2];
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	int ans = 0, L = 0;
	for(R = 1; R <= n; R++) {
		add(a[R]);
		while(good) {
			ans += R - L;
			remove(a[L++]);
		}
	}
	cout << ans;
}