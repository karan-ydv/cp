#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e7 + 5;
int spf[N], prime[N];
int dp[N], A[N];

void linearsieve(int N)
{
    int c = 0;
    for (int i = 2; i < N; i++)
    {
        if (spf[i] == 0)
            spf[i] = i, prime[c++] = i;
        for (int j = 0; j < c and prime[j] <= spf[i]; j++)
        {
            int x = i * prime[j];
            if (x >= N)
                break;
            spf[x] = prime[j];
        }
    }
}

int n, q;
void precum(int mx)
{
    linearsieve(mx + 1);
    for (int i = 0; i < n; i++)
    {
        while (A[i] != 1)
        {
            int p = spf[A[i]];
            dp[p] += 1;
            while (spf[A[i]] == p)
                A[i] /= p;
        }
    }
    partial_sum(dp, dp + mx + 2, dp);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cin >> q;
    int mx = *max_element(A, A + n);
    precum(mx);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if(l > mx)
        {
            cout << "0\n";
            continue;
        }
        r = min(r, mx + 1);
        cout << dp[r] - dp[l - 1] << '\n';
    }
}