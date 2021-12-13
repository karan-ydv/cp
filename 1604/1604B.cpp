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
        bool flag = false;
        if(n & 1)
        {
            for(int i = 1; i < n; i++)
            if(a[i] <= a[i - 1]) 
            {
                flag = true;
                break;
            }
        }
        else    flag = true;
        flag ? cout << "YES\n" : cout << "NO\n";
    }
}