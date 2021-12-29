#include <bits/stdc++.h>
using namespace std;
int ans[100069], c;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int sum, limit;
    cin >> sum >> limit;
    for(int b = 1 << 21; sum and b; b >>= 1) if(b <= limit)
        for(int j = b; sum >= b and j <= limit; j += 2 * b)
            sum -= b, ans[c++] = j;
    if(sum) return cout << "-1", 0;
    cout << c << '\n';
    for(int i = 0; i < c; i++)
        cout << ans[i] << ' ';
}