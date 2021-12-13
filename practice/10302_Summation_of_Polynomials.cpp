#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n)
    {
        n *= (n + 1);
        n /= 2;
        n *= n;
        cout << n << '\n';
    }
}