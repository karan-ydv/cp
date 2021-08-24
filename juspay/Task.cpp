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
        unordered_map<int, int> mp;
        for(int x: a)
        {
            for(int i = 2; i <= sqrt(x); i++)
            {
                for(int j = 1; x % i == 0; j++)
                {
                    
                }
            }
        }
    }
}