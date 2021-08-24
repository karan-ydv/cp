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
        int a[n]; for(int &x: a)    cin >> x;
        int sum = accumulate(a, a + n, 0);
        if(sum % n == 0)
        {
            int avg = sum / n, ans = 0;
            for(int x: a) ans += x > avg;
            cout << ans << '\n';
        }
        else cout << "-1\n";
    }
}