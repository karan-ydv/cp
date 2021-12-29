#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        string s;   cin >> s;
        int ans = n;
        for(char c = 'a'; c <= 'z'; c++)
        {
            int l = 0, r = n - 1;
            int cnt = 0, f = 0;
            while(l < r)
            {
                if(s[l] != s[r])
                {
                    if(s[l] != c and s[r] != c) {
                        f = 1; break;
                    }
                    cnt++;
                    if(s[l] == c)  l++;
                    if(s[r] == c)  r--;                    
                }
                else l++, r--;
            }
            if(f == 0)
                ans = min(ans, cnt);
        }
        if(ans == n)
            ans = -1;
        cout << ans << '\n';
    }
}