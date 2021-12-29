#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int t;	cin >> t;
    while(t--)
    {
        int n, x;   cin >> n >> x;
        if(n == 1)
        {
            int y;  cin >> y;
            if(y > 0)
                cout << "0\n";
            else
                cout << "1\n";
            continue;
        }

        int p = n / 2, q = n - p;
        int a[p], b[q];
        for(int &x: a)  cin >> x;
        for(int &x: b)  cin >> x;
        unordered_set<int> set;
        int ans = 0;
        for(int i = 0; i < (1 << n); i++) {
            int p = 1;
            long double pp = 1;
            for(int j = 0, b = 1; b <= i and pp <= x; j++, b <<= 1)
            if(i & b)
            {
                pp *= a[j];
                p *= a[j];
            }
            if(pp <= x)
            {
                ans
            }
        }
    }
}