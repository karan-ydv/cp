#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve()
{
    int n;	cin >> n;
    if(n % 4 == 0)
    {
        cout << "YES\n";
        int A[n / 2], c = n / 2 - 1;
        for(int i = 0; i < n / 4; i++)
        {
            int a = 4 * i + 1;
            int b = a + 3;
            A[c--] = a;
            A[c--] = b;
        }
        for(int x: A)   cout << x << ' ';
        cout << '\n';
        for(int i = 0; i < n / 4; i++)
        {
            int a = 4 * i + 2;
            int b = a + 1;
            cout << a << ' ' << b << ' ';
        }
        cout << '\n';
    }
    else cout << "NO\n";
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