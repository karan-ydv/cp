#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 998244353;

const int N = 505;
int dp[N], count[N];
multiset<int> set[N];

// dp[i] = sum of f(B) of subsequences upto i

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    pair<bool, int> A[n + 1];
    for(int i = 1; i <= n; i++)
    {
        char ch;    cin >> ch;
        A[i].first = ch == '+';
        if(ch == '+')
            cin >> A[i].second;
    }
    for(int i = 1; i <= n; i++)
    {
        if(A[i].first)
        {
            int x;  // number of subsets with smallest value less than A[i]
            int sumx; // number of subsets with smallest value larger than A[i]
            dp[i] = dp[i - 1];  
            dp[i] += dp[]
        }
        else
        {
            dp[i] = dp[i - 1];  // when S[i] is not taken
            dp[i] += 0;         // when S[i] is included
        }
    }
}