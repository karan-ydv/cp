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
        int n;	cin >> n; int a[n];
        int sum = 0;
        for(int &x: a)    cin >> x, sum += x;
        cout << sum - *max_element(a, a + n) << '\n';
    }
}