#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool fun(int a, int b, int n)
{
    if(a == 1)
    return (n - 1) % b == 0;
    for(int p = 1; p <= n; p *= a)
    {
        int x = n - p;
        if(x % b == 0)
            return true;
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, a, b;    cin >> n >> a >> b;
        if(fun(a, b, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}