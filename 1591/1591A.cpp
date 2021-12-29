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
        int h = 1;
        for(int i = 0, p = 1 - a[0]; i < n; i++)
        {
            if(a[i] == 1)
            {
                if(p == 1)
                    h += 5;
                else
                    h += 1;
            }
            else if(p == 0)
            {
                h = -1;
                break;
            }
            p = a[i];
        }
        cout << h << '\n';
    }
}