#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cout << i * i * (i * i - 2 * i + 1) / 2 << '\n';
    }
}