#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 2002;
int dp[N][2], up[N];

// dp[i][0] = minimum time such that all numbers < ai have been written
// dp[i][1] = minimum time such that all numbers <= ai have been written

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s;   cin >> n >> s;
    int A[n];   for(int &x: A)  cin >> x;
    int B[n];   iota(B, B + n, 0);
    sort(B, B + n, [&](int i, int j) {
        return (A[i] < A[j]) || (A[i] == A[j] && i < j);
    });
    s--;
    // for(int x: B)   cerr << x <<' '; cerr << '\n';
    // for(int x: B)   cerr << A[x] << ' '; cerr << '\n';
    for(int i = 0; i < n and A[B[i]] == A[0]; i++)
    {
        dp[i][1] = min((s - B[i] + n) % n, (B[i] - s + n) % n);
        cerr << dp[i][1] << '\n';
    }
    int mn;
    for(int i = 1; i < n; i++)
    {
        int j;
        for(j = i; j < n and A[B[j]] == A[B[i]]; j++) dp[j][0] = dp[mn];
        for(int k = p; k < )
    }
}