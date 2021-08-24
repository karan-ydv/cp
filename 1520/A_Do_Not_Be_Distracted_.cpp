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
        string s;
        int n;	cin >> n >> s;
        bool flag = true;
        bool vis[26] = {0};
        for(int i = 0; i < n; )
        {
            if(vis[s[i]-'A'])
            {
                flag = false;
                break;
            }
            vis[s[i] - 'A'] = 1;
            int j = i + 1;
            for(; j < n ; j++)
            {
                if(s[j] != s[i])    break;
            }
            i = j;
        }
        if(flag)    cout << "YES\n";
        else        cout << "NO\n";
    }
}