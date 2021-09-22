#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int n = s.length();
    s = "!" + s + "!";
    for(int i = 1; i <= n; i++)
    if(s[i] == 'H')
    {
        if(s[i - 1] != '-' and s[i + 1] != '-')
            return -1;
    }
    string x = "!";
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '-')    x += '-';
        else if(x.back() != 'H')
            x += 'H';
    }
    cerr << x << '\n';
    int ans = 0;
    for(int i = 0; i < x.length(); i++) if(s[i] == 'H') {
        int c = 0;
        for(; i < x.length() and x[i] == 'H'; i += 2, c++);
        ans += (c + 1) / 2;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;   cin >> s;
    cout << solution(s);
}