#include <bits/stdc++.h>
using namespace std;

unsigned int binarytoint(string s)
{
    reverse(s.begin(), s.end());
    unsigned int b = 1, x = 0;
    for(char c: s)
    {
        if(c == '1')    x += b;
        b <<= 1;
    }
    return x;
}
void printbinary(unsigned int n)
{
    string s = "";
    while(n)
    {
        if(n & 1)   s += "1";
        else        s += "0";
        n >>= 1;
    }
    reverse(s.begin(), s.end());
    cerr << s << '\n';
}
int bfs(int s, int e)
{
    set<int> visited;
    queue<pair<int, int>> q;
    q.push({s, 0});
    visited.insert(s);
    while(!q.empty())
    {
        auto [x, d] = q.front();
        // printbinary(x);
        q.pop();
        if(x == e)  return d;
        if(d < 20)
        {
            if(!visited.count(x << 1));
                q.push({x << 1, d + 1});
            
            if(x == 0)  x = 1;
            else        x = (~x) & ((1 << 32 -__builtin_clz(x)) - 1);
            if(!visited.count(x));
                q.push({x, d + 1});
        }
    }
    return -1;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        string a, b;    cin >> a >> b;
        unsigned s = binarytoint(a);
        unsigned e = binarytoint(b);
        int ans = bfs(s, e);
        if(ans == -1)
        cout << "Case #" << _ << ": " << "IMPOSSIBLE" << '\n';
        else
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}