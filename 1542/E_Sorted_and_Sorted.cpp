#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 2021;
int dp[N][N], B[N], W[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    for(int i = 0, j = 0; i + j < n + n; )
    {
        string c;   cin >> c;
        if(c == "B")
            cin >> B[i++];
        else
            cin >> W[j++];
    }

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    {
        
    }
}