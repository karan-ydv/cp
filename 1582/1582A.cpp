#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << (a + 2 * b + 3 * c) % 2 << '\n';
    }
}