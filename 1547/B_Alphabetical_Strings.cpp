#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool fun(string &s)
{
    char last = 'a' + s.length() - 1;
    deque<char> q;
    for(char c: s)  q.push_back(c);

    while(!q.empty())
    {
        if(q.front() != last and q.back() != last)
            return false;
        if(q.front() == last)
            q.pop_front();
        else
            q.pop_back();
        last--;
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        string s; cin >> s;
        if(fun(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}