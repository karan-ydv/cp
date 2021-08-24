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
        int sum = 0;
        for(int i = 0; i < 6; i++)
        {
            int x;  cin >> x;
            sum += i < 3 ? x : -x;
        }
        if(sum > 0)
            cout << "1\n";
        else
            cout << "2\n";
    }
}