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
        deque<int> q;
        int a[n], cnt = 0;
        for(int &x: a)
        {
            cin >> x;
            cnt += x & 1;
            if(x & 1)
                q.push_back(x);
            else
                q.push_front(x);
        }
        if(cnt == 0 or cnt == n)
            cout << "-1\n";
        else
        {
            while(!q.empty())
            {
                cout << q.front() << ' ';
                q.pop_front();
            }
            cout << '\n';
        }
    }
}