#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+69;
int freq[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    for(int i = 1, x, s = 0; i <= n; i++)
    {
        cin >> x, x %= n;
        (s += x + n) %= n;
        freq[s]++;
    }

    int64_t ans = freq[0];
    for(int i = 0; i < n; i++)
        ans += (int64_t)freq[i] * (freq[i] - 1) / 2;
    cout << ans;
}