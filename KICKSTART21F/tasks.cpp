#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    tuple<int, int, int> A[n];

    for(int i = 0; i < n; i++)
        cin >> get<1>(A[i]);
    for(int i = 0; i < n; i++)
        cin >> get<2>(A[i]),
        get<0>(A[i]) = get<1>(A[i]) - get<2>(A[i]);
    sort(A, A + n, greater<tuple<int, int, int>>());

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int d = get<0>(A[i]);
        int a = get<1>(A[i]);
        int b = get<2>(A[i]);
        if(d > 0)
        {
            if(x)
                ans += a, x--;
            else
                ans += b, y--;
        }
        else
        {
            if(y)
                ans += b, y--;
            else
                ans += a, x--;
        }
    }
    cout << ans;
}