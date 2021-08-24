#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+69;
int dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        tuple<int, int, int> A[n];
        for(int i = 0; i < n; i++)
            get<2>(A[i]) = i + 1;
        for(auto &[a, b, c]: A) cin >> b;
        for(auto &[a, b, c]: A) cin >> a;
        sort(A, A + n);
        for(auto &[a, b, c]: A)
        cerr << b << ' ' << a << ' ' << c << '\n';
        int mx = get<0>(A[n - 1]);
        memset(dp, 0, mx + 1);
        for(auto [a, b, c]: A)
        if(a >= b)
        {
            for(int i = a; i >= b; i--)
                dp[i] = max(dp[i], dp[i - b] + 1);
        }
        cerr << dp[mx] << '\n';
        for(int i = 0; i <= mx; i++)
            cerr << dp[i] << " \n"[i == mx];
        cerr << '\n';
    }
}