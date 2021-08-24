#include <bits/stdc++.h>
using namespace std;

int solve(int N, int S, string M)
{
    string s = to_string(N);
    int f[10] = {}, g[10] = {};
    for(char c: s)
    {
        if(c == '5')
            f[2]++;
        else if(c == '9')
            f[6]++;
        else
            f[c - '0']++;
    }
    for(char c: M)
    {
        if(c == '5')
            g[2]++;
        else if(c == '9')
            g[6]++;
        else
            g[c - '0']++;
    }
    int cnt = INT_MAX;
    for(int i = 0; i < 10; i++) if(f[i])
    {
        int x = g[i] / f[i];
        cnt = min(cnt, x);
    }
    return cnt;
}

int main()
{
    int t;  cin >> t;
    while(t--)
    {
        int N, S;
        string M;
        cin >> N >> S >> M;
        cout << solve(N, S, M) << '\n';
    }
}