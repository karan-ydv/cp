#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve()
{
    int N;  cin >> N; N <<= 1;
    int s = (int) sqrt(N);
    for(int n = s; n > 1; n--)
    if(N % n == 0)
    {
        int m = N / n;
        int L = (m - n + 1);
        if(L & 1)   continue;
        clog << n << ' ' << m << '\n';
        L >>= 1;
        cout << L << ' ' << L + n - 1 << '\n';
        return;
    }

    cout << "-1\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        solve();
    }
}