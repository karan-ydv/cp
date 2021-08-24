#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    s = "!" + s, t = "!" + t;

    for(int i = 1; i <= n; i++) dp[i][0] = i;
    for(int i = 1; i <= m; i++) dp[0][i] = i;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        int a = dp[i - 1][j] + 1;
        int b = dp[i][j - 1] + 1;
        int c = dp[i - 1][j - 1] + (s[i] != t[j]);
        dp[i][j] = min({a, b, c});
    }
    stack<tuple<string, int, char>> stack;
    for(int i = n, j = m; i >= 0 and j >= 0; )
    {
        if(dp[i][j] == dp[i - 1][j] + 1)
        {
            stack.push({"DELETE", i, 'a'});
            i = i - 1;
        }
        else if(dp[i][j] == dp[i][j - 1] + 1)
        {
            stack.push({"INSERT", i + 1, t[j]});
            j -= 1;
        }
        else
        {
            if(s[i] != t[j])
                stack.push({"REPLACE", i, t[j]});
            i--, j--;
        }
    }
    int d = 0;
    cout << stack.size() << '\n';
    while(!stack.empty())
    {
        auto [a, b, c] = stack.top();
        cout << a << ' ' << b + d << ' ';
        if(a != "DELETE")   cout << c;
        cout << '\n';
        d += a == "INSERT";
        d -= a == "DELETE";
        stack.pop();
    }
}