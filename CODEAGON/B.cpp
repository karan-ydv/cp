#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int solve(int a, int b) {
    if(a == 0 and b == 0)
        return 0;
    int s = sqrt((long long) a * b);
    int ret = 1 << 30;
    if(a != 0)  ret = min(ret, 1 + solve(a / 2, b));
    if(b != 0)  ret = min(ret, 1 + solve(a, b / 2));
    if(s < a or s < b)
        ret = min(ret, 2 + solve(s, s));
    return ret;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;   cin >> a >> b;
    cout << solve(a, b);
}