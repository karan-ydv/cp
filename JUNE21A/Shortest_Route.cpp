#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5+69;
int A[N], pref[N], suff[N], ans[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, m;   cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> A[i];
        pref[0] = suff[n + 1] = 1e9;
        for(int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + 1;
            if(A[i] == 1) pref[i] = 0;
        }
        for(int i = n; i >= 1; i--)
        {
            suff[i] = suff[i + 1] + 1;
            if(A[i] == 2) suff[i] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            ans[i] = min(pref[i], suff[i]);
            if(ans[i] >= 1e9)   ans[i] = -1;
        }
        ans[1] = 0;
        for(int i = 0; i < m; i++)
        {
            int x;  cin >> x;
            cout << ans[x] << ' ';
        }
        cout << '\n';
    }
}