#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e3+69;
int A[N][N], B[N][N], dp[N][N];
int h, w, c, ans;

void fun()
{
    dp[1][1] = 1e18;

    for(int i = 2; i <= h; i++) {
        dp[i][1] = A[i][1] + c + min(dp[i - 1][1] - A[i - 1][1], A[i - 1][1]);
        ans = min(ans, dp[i][1]);
    }
    for(int j = 2; j <= w; j++) {
        dp[1][j] = A[1][j] + c + min(dp[1][j - 1] - A[1][j - 1], A[1][j - 1]);
        ans = min(ans, dp[1][j]);
    }

    for(int i = 2; i <= h; i++)
    for(int j = 2; j <= w; j++)
    {
        dp[i][j] = A[i][j] + c + min({dp[i - 1][j] - A[i - 1][j], A[i - 1][j],
                                      dp[i][j - 1] - A[i][j - 1], A[i][j - 1]});
        ans = min(ans, dp[i][j]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w >> c;

    for(int i = 1; i <= h; i++)
    for(int j = 1; j <= w; j++)
    {
        cin >> A[i][j];
        B[i][w + 1 - j] = A[i][j];
    }
    ans = 1e18;
    fun();
    swap(A, B);
    fun();
    cout << ans;
}