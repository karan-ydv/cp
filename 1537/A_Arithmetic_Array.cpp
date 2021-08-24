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
        int n;	cin >> n;
        int a[n]; for(int &x: a)    cin >> x;
        int sum = accumulate(a, a + n, 0ll);
        if(sum < n)
            cout << "1\n";
        else if(sum == n)
            cout << "0\n";
        else
            cout << sum - n << '\n';
    }
}