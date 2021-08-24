#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;   cin >> n >> q;
    int a[n];   for(int &x: a)  cin >> x;
    sort(a, a + n);
    int b[n], prev = 0;
    for(int i = 0; i < n; i++)
    {
        b[i] = a[i] - prev - 1;
        prev = a[i];
    }
    partial_sum(b, b + n, b);
    while(q--)
    {
        int k;  cin >> k;
        int i = lower_bound(b, b + n, k) - b;
        if(i == 0)
            cout << k << '\n';
        else
        {
            i--;
            cout << a[i] + k - b[i] << '\n';
        }
    }
}