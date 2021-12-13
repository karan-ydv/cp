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
        int n, k; string s;
        cin >> n >> k >> s;
        int p = 0;
        while(p < n and s[p] == '0') p++;
        for(int i = p; i < n; i++)
        if(s[i] == '0')
        {
            if(i - p <= k)
            {
                swap(s[i], s[p]);
                k -= i - p;
            }
            else
            {
                swap(s[i], s[i - k]);
                k = 0;
            }
            p++;
        }
        cout << s << '\n';
    }
}