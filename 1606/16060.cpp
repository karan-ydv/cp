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
        int ans = 0;
        for(int i = 0; i + 1 < n; )
        {
            if(s[i] == 'a' and s[i + 1] == 'b')
            {
                int x = i + 1;
                bool flag = true;
                for(int j = x + 1; j < n; j++) {
                    x = j;
                    if(s[j] == 'a')
                    {
                        flag = false;
                        break;
                    }
                }
                i = x;
                if(flag)
                {
                    s[x] = 'a';
                    ans++;
                }
            }
            else if(s[i] == 'b' and s[i + 1] == 'a')
            {
                int x = i + 1;
                bool flag = true;
                for(int j = x + 1; j < n; j++) {
                    x = j;
                    if(s[j] == 'b')
                    {
                        flag = false;
                        break;
                    }
                }
                i = x;
                if(flag)
                {
                    s[x] = 'b';
                    ans++;
                }
            }
            else i++;
        }
        cerr << ans << '\n';
        cout << s << '\n';
    }
}