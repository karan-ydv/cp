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
        int n, p;   cin >> n >> p;
        int X[n], Y[n], R[n], A[n];
        for(int &x: X)  cin >> x;
        for(int &y: Y)  cin >> y;
        for(int &x: A)  cin >> x;
        for(int i = 0; i < n; i++)
            R[i] = X[i] * X[i] + Y[i] * Y[i];
        
        if(accumulate(A, A + n, 0ll) < p) {
            cout << "-1\n"; continue;
        }

        auto fun = [&](int r)
        {
            int sum = 0;
            for(int i = 0; i < n; i++)
                if(R[i] <= r)   sum += A[i];
            return sum >= p;
        };
        
        int beg = 0, end = 3e8, ans = -1;
        while(beg <= end)
        {
            int mid = beg + end >> 1;
            if(fun(mid * mid))
                end = mid - 1, ans = mid;
            else
                beg = mid + 1;
        }
        cout << ans << '\n';
    }
}