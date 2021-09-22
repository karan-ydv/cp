#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5;
int A[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, k;   cin >> n >> k;
        fill_n(A + 1, n + 1, 0);
        for(int i = 0; i < n; i++) {
            int x;  cin >> x;
            A[x]++;
        }
        sort(A + 1, A + n + 1, greater<int>());
        int ans = 0, cnt = n;
        for(int i = 1; i <= n; i++)
        {
            if(A[i] > k)
            {
                ans ++;
                cnt -= A[i];
            }
            else
            {
                ans += (cnt + k - 1) / k;
                break;
            }
        }
        cout << ans << '\n';
    }
}