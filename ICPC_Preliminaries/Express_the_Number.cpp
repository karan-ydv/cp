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
        int n, x;   cin >> n >> x;
        if(x == 0 and n & 1)
        {
            cout << "-1\n";
            continue;
        }
        int eve = 0;
        if(n & 1)
        {
            eve = 1;
            n -= 1;
        }
        vector<int> v;
        for(int b = 1, i = 0; i <= 31; b <<= 1, i++)
        if(n & b)
        {
            if(i & 1)
                v.push_back(b);
            else
            {
                v.push_back(b >> 1);
                v.push_back(b >> 1);
            }
        }
        sort(v.begin(), v.end());
        int ans = v.size();
        for(int b: v)
        {
            if(eve + b > x)   break;
            eve += b;
            ans --;
        }
        if(eve > 0)
            ans++;
        cout << ans << '\n';
    }
}