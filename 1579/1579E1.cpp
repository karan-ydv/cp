#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[n];
        for(int &x: a)  cin >> x;
        deque<int> q;
        q.push_back(a[0]);
        for(int i = 1; i < n; i++) {
            if(a[i] < q.front())    q.push_front(a[i]);
            else                    q.push_back(a[i]);
        }
        for(int x: q)   cout << x << ' '; cout << '\n';
    }
}