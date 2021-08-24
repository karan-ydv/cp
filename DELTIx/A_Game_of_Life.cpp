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
        string s;   cin >> s;
        s = "!" + s;
        int pref[n + 2], suff[n + 2];
        pref[0] = suff[n + 1] = 1e9;
        for(int i = 1; i <= n; i++) {
            if(s[i] == '1') pref[i] = 0;
            else            pref[i] = pref[i - 1] + 1;
        }
        for(int i = n; i >= 0; i--) {
            if(s[i] == '1') suff[i] = 0;
            else            suff[i] = suff[i + 1] + 1;
        }
        for(int i = 1; i <= n; i++)
        {
            if(s[i] == '1') cout << '1';
            else
            {
                if(pref[i - 1] == suff[i + 1])
                    cout << '0';
                else if(min(pref[i - 1], suff[i + 1]) < m)
                    cout << '1';
                else
                    cout << '0';
            }
        }
        cout << '\n';
    }
}