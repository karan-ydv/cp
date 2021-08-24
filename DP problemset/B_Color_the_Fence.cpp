#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v, a[10];
    cin >> v;
    for (int i = 1; i <= 9; i++)
        cin >> a[i];
    
    int mn = min_element(a + 1, a + 10) - a;
    int len = v / a[mn];
    v %= a[mn];
    if(len == 0)    return cout << "-1", 0;

    string ans = string(len, '0' + mn);
    for(int i = 0; i < len; i++)
    {
        for(int j = 9; j >= 1; j--)
        if(v + a[mn] >= a[j])
        {
            ans[i] = '0' + j;
            v -= a[j] - a[mn];
            break;
        }
    }
    cout << ans;
}