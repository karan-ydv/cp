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
        if(n & 1)
            cout << "NO\n";
        else
        {
            n >>= 1;
            int x = sqrt(n);
            if(x * x == n)
                cout << "YES\n";
            else
            {
                if(n & 1)
                    cout << "NO\n";
                else
                {
                    n >>= 1;
                    int x = sqrt(n);
                    if(x * x == n)
                        cout << "YES\n";
                    else
                        cout << "NO\n";
                }
            }
        }
    }
}