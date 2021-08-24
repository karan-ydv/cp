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
        int a[n], b[n];
        for(int &x: a)  cin >> x;
        for(int &x: b)  cin >> x;
        
        int mn = 1e9;
        for(int i = 0; i < n; i++)
            mn = min(mn, (a[0] + b[i]) % n);
        
        vector<int> c(n, 1e9);
        for(int i = 0; i < n; i++)
        if((a[0] + b[i]) % n == mn)
        for(int j = 0; j < n; j++)
        {
            int x = (a[j] + b[(i + j) % n]) % n;
            if(x == c[j])   continue;
            if(c[j] > x)
            {
                for(; j < n; j++)
                    c[j] = (a[j] + b[(i + j) % n]) % n;
            }
            break;
        }

        for(int i = 0; i < n; i++)        
            cout << c[i] << " \n"[i == n - 1];
    }
}