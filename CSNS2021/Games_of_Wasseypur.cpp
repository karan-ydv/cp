#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
bool dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp[1] = 1;
    for(int i = 3; i < N; i++)
        dp[i] = (!dp[i - 1]) or (!dp[i - 2]);

    int t;	cin >> t;
    while(t--)
    {
        string s; int n;
        cin >> n >> s;
        int cnt = 1;
        char p = s[0];
        for(char c: s)
        {
            cnt += c != p;
            p = c;
        }
        dp[cnt] ? cout << "SAHID\n" : cout << "RAMADHIR\n";
    }
}