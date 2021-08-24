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
        int a[n];
        for(int &x: a)  cin >> x;
        int mn = *min_element(a, a + n);
        int ans = 0;
        for(int i = 0; i < n; i++)
        if(a[i] != mn)
        {
            // there exists M such that a[i] % M = mn
            ans++;
            if(mn > ((a[i] - 1) / 2) )
            {
                ans = n;
                break;
            }
        }
        cout << ans << '\n';
    }
}