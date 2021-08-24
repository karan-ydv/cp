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
        int n, m, p;	cin >> n >> m >> p;
        string s[n];
        int f[m];
        int x = (n + 1) / 2;
        for(int i = 0; i < n; i++)
        {
            cin >> s[i];
            for(int j = 0; j < m; j++)  f[j]++;
        }
        vector<int> v;
        for(int i = 0; i < m; i++)
        {
            if(f[i] >= x)
            v.push_back(i);
        }
        int k = v.size();
        for(int i = 0; i < (1 << k); i++)
        {
            bitset<20> b(i);
            for(int j = 0; j < k; j++) {
                if(s[])
            }
        }
    }
}