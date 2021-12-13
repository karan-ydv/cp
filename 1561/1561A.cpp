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
        int a[n];   for(int &x: a)  cin >> x;
        for(int i = 0; ; i++)
        {
            if(is_sorted(a, a + n))
            {
                cout << i << '\n';
                break;
            }
            for(int j = i & 1; j + 1 < n; j += 2)
                if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}