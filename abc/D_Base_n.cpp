#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string x; int m;
    cin >> x >> m;

    reverse(x.begin(), x.end());

    int n = x.length();
    if(n == 1)
        return (cout << (stoi(x) <= m)), 0;
    
    int d = (*max_element(x.begin(), x.end()) - '0');
    int beg = d + 1, end = 1e18, ans = 0;
    while(beg <= end)
    {
        int mid = (beg + end) / 2;
        long double val = 0, p = 1;
        for(int i = 0; i < n and val < 2e18; i++, p *= mid)
            val += (x[i] - '0') * p;
        
        if(val <= m)
            beg = mid + 1, ans = mid - d;
        else
            end = mid - 1;            
    }

    cout << ans;
}