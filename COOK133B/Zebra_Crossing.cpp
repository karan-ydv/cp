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
        int n, k;   cin >> n >> k;
        string s;   cin >> s;
        s = "!" + s + "!";
        deque<int> q;
        int i = 1;
        for(int i = 1; i <= n; i++)
            if(s[i] != s[i + 1])
                q.emplace_back(i);
        if(!q.empty()) q.pop_front();
        if(!q.empty())
        {
            if(k & 1)
            {
                if(s[q.back()] == s[1])
                    q.pop_back();
            }
            else
            {
                if(s[q.back()] != s[1])
                    q.pop_back();
            }
        }
        if(q.size() >= k)
            cout << q.back() << '\n';
        else
            cout << "-1\n";
    }
}