#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5+69;
int a[N], p[N][19];

bool good(int l, int r, int k)
{
    while(k and l <= r)
    {
        l = p[l][__builtin_ctzll(k)];
        k &= (k - 1);
    }
    return l > r;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, k, s;
        cin >> n >> k >> s;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        partial_sum(a, a + n + 1, a);
        a[n + 1] = 1e18;
        p[n + 1][0] = n + 1;
        for(int i = n; i > 0; i--)
        {
            int beg = i + 1, end = n + 1;
            while(beg <= end)
            {
                int mid = beg + end >> 1;
                if(a[mid] - a[i - 1] > s)
                    p[i][0] = mid, end = mid - 1;
                else
                    beg = mid + 1;
            }
        }
        
        for(int i = 1; i < 19; i++)
        for(int j = 1; j <= n + 1; j++)
            p[j][i] = p[p[j][i - 1]][i - 1];

        // for(int i = 0; i <= n; i++)
        //     cerr << a[i] << " \n"[i == n];
        // for(int i = 0; i <= n; i++)
        //     cerr << p[i][1] << " \n"[i == n];

        int ans = 1, L = 1;
        for(int R = 1; R <= n; R++)
        {
            while(L <= R and !good(L, R, k))
                L++;
            ans = max(ans, R - L + 1);
        }
        cout << ans << '\n';
    }
}