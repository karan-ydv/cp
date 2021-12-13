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
        string s; int n;
        cin >> n >> s;
        s = "!" + s;
        int f[26][n + 1]{};
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < 26; j++)
                f[j][i] = f[j][i - 1];
            f[s[i] - 'A'][i]++;
        }
        int q; cin >> q;
        while(q--)
        {
            int l, r, k;
            cin >> l >> r >> k;
            
        }
    }
}