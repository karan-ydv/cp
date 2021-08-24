#include <bits/stdc++.h>
#define int int64_t
using namespace std;


int manhattan(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, m, i, j; cin >> n >> m >> i >> j;
        pair<int, int> A[] = {{1, 1}, {1, m}, {n, 1}, {n, m}};

        pair<int, int> ans;
        int mx = -1;
        for(int a = 0; a < 4; a++)
        for(int b = 0; b < 4; b++)
        {
            int d = manhattan({i, j}, A[a]) + manhattan(A[a], A[b]) + manhattan(A[b], {i, j});
            if(d > mx)
            {
                mx = d;
                ans = {a, b};
            }
        }
        auto [a, b] = ans;
        // cerr <<  manhattan({i, j}, A[2]) + manhattan(A[2], A[3]) + manhattan(A[3], {i, j}) << ' ';
        // cerr << mx << '\n';
        cout << A[a].first << ' ' << A[a].second << ' '
             << A[b].first << ' ' << A[b].second << '\n';
    }
}