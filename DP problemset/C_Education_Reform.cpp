#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct subject
{
    int a, b, c, idx;
};
bool operator<(const subject &x, const subject &y)
{
    return x.c < y.c;
}

int dp[105][105][55];
pair<int, int> up[105][105][55];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i = 1, n, m, k; cin >> n >> m >> k; subject A[m];
    for (auto &x : A) cin >> x.a >> x.b >> x.c, x.idx = i++;

    sort(A, A + m);

    int mx = 0, a = 0, b = 0, d;
    for (int i = 0; i < m; i++)                         // current subject
    for (int y = 0; A[i].a + y <= A[i].b; y++)          // if ai + y excercises are given
    {
        dp[i][y][1] = A[i].a + y;
        for (int z = 1; z < n; z++) if (dp[i][y][z] != 0)   // if this state is reachable
        for (int j = i + 1; j < m; j++) if (A[j].c > A[i].c)
        {
            d = (A[i].a + y) * k - A[j].a;
            if (0 <= d and d <= 100)
            if (dp[j][d][z + 1] < dp[i][y][z] + k * (A[i].a + y))
            {
                dp[j][d][z + 1] = dp[i][y][z] + k * (A[i].a + y);
                up[j][d][z + 1] = {i, y};
            }

            d = A[i].a + y + k - A[j].a;
            if (0 <= d and d <= 100)
            if (dp[j][d][z + 1] < dp[i][y][z] + k + (A[i].a + y))
            {
                dp[j][d][z + 1] = dp[i][y][z] + k + (A[i].a + y);
                up[j][d][z + 1] = {i, y};
            }
        }
        if ( dp[i][y][n] > mx)
        {
            a = i, b = y;
            mx = dp[i][y][n];
        }
    }

    if (mx == 0) return cout << "NO", 0;

    stack<pair<int, int>> stack;
    for (int i = n; i > 0; i--)
    {
        stack.push({A[a].idx, A[a].a + b});
        auto [x, y] = up[a][b][i];
        a = x, b = y;
    }

    cout << "YES\n";
    while (!stack.empty())
    {
        cout << stack.top().first << ' ' << stack.top().second << '\n';
        stack.pop();
    }
}