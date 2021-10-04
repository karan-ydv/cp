#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve()
{

    int n;	cin >> n;
    int a[n];   for(int &x: a)  cin >> x;
    for(int i = 0; i <= n / 2; i++)
    if(a[i] != i + 1 or a[n - 1 - i] != i + 1)
        return cout << "no\n", void();
    cout << "yes\n";
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