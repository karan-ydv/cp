#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e6+5;
bool f[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        string a, b;    cin >> a >> b;
        f[n] = false;
        int ans = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(a[i] < b[i])
                f[i] = true;
            else if(a[i] == b[i])
                f[i] = f[i + 1];
            else
                f[i] = false;
            ans += f[i];
        }
        cout << ans << '\n';
    }
}