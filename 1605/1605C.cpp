#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+6;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n; string s;
        cin >> n >> s;
        int ans = 8;
        for(int i = 0; i < n; i++)
        {
            int a[3]{};
            for(int j = i; j < min(n, i + 7); j++)
            {
                a[s[j] - 'a']++;
                if(a[0] > max({1, a[1], a[2]}))
                    ans = min(ans, j - i + 1);
            }
        }
        cout << (ans == 8 ? -1 : ans) << '\n';
    }
}