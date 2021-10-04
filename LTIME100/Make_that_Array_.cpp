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
        int a[n];   for(int &x: a)  cin >> x, x--;
        int b[n];   for(int &x: b)  cin >> x, x--;

        int A[n];
        for(int i = 0; i < n; i++)
        {
            A[i] = 
        }

        int p[n];
        for(int i = 0; i < n; i++)  p[b[i]] = i;
        for(int i = 0; i < n; i++)  a[i] = p[a[i]];
        for(int x: a)   cerr << x << ' '; cerr << '\n';
    }
}