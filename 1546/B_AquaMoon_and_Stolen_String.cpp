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
        int n, m;   cin >> n >> m;
        vector<string> a(n), b(n - 1);
        vector<int> sum(m);
        for(auto &s : a)    cin >> s;
        for(auto &s : b)    cin >> s;
        for(auto &s: a)
        for(int i = 0; i < m; i++)
            sum[i] += s[i];
        for(auto &s: b)
        for(int i = 0; i < m; i++)
            sum[i] -= s[i];
        for(int x: sum)
            cout << char(x);
        cout << endl;
    }
}