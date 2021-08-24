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
        string s;   cin >> s;
        int n = s.length();
        s += "!!";
        int nxt[n + 3][2];
        
        if(s[n - 1] == '?')
            nxt[n - 1][0] = nxt[n - 1][1] = n - 1;
        else
            nxt[n - 1][s[n - 1] - '0'] =  n - 1, nxt[n - 1][1 - s[n - 1] + '0'] = -1;

        int ans = 1;
        for(int i = n - 2; i >= 0; i--)
        {
            if(s[i] == '?')
            {
                nxt[i][0] = nxt[i][1] = i;
                if(s[i + 1] != '0')
                    nxt[i][0] = nxt[i + 1][1];
                if(s[i + 1] != '1')
                    nxt[i][1] = nxt[i + 1][0];
            }
            else if(s[i] == '0')
            {
                nxt[i][1] = -1;
                nxt[i][0] = max(nxt[i + 1][1], i);
            }
            else
            {
                nxt[i][0] = -1;
                nxt[i][1] = max(nxt[i + 1][0], i);
            }
            ans += (max(nxt[i][0], nxt[i][1]) - i + 1);
        }
        cout << ans << '\n';
    }
}