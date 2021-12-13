#include <bits/stdc++.h>
using namespace std;

struct MinQ {
    deque<int> q;
    void push(int x) {
        while(!q.empty() and x < q.back())
            q.pop_back();
        q.push_back(x);
    }
    void pop(int x) {
        if(q.front() == x)
            q.pop_front();
    }
    int val() {return q.front();}
};

struct MaxQ : MinQ {
    void push(int x) {
        while(!q.empty() and x > q.back())
            q.pop_back();
        q.push_back(x);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[n];   for(int &x: a)  cin >> x;
        string s;   cin >> s;
        int ans = -2e9;
        MinQ q1;
        MaxQ q2;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'B')
                q2.push(a[i]);
            else
                q1.push(a[i]);
        }
        int ans = q2.val() - q1.val();
        for(int i = 0; )
    }
}