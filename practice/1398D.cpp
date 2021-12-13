#include <bits/stdc++.h>

namespace r = std::ranges;
namespace v = std::views;
using namespace std;

const int N = 202;
int dp[N][N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, g, b;    cin >> r >> g >> b;
    vector<int> R(r), G(g), B(b);
    for(int &x: R)  cin >> x;
    for(int &x: G)  cin >> x;
    for(int &x: B)  cin >> x;
    r::sort(v::reverse(R));
    r::sort(v::reverse(G));
    r::sort(v::reverse(B));

    R.emplace_back(0);
    G.emplace_back(0);
    B.emplace_back(0);

    int ans = 0;
    for(int i = 0; i <= r; i++)
    for(int j = 0; j <= g; j++)
    for(int k = 0; k <= b; k++)
    {
        dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + R[i] * G[j]);
        dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + G[j] * B[k]);
        dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + B[k] * R[i]);
        ans = max(ans, dp[i][j][k]);
    }
    cout << ans;
}