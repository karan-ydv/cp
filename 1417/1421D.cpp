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
        int x, y;   cin >> x >> y;
        int c[6];   for(int &x: c)  cin >> x;
        for(int i = 0; i < 6; i++)
            c[i] = min(c[i], c[(i + 1) % 6] + c[(i + 5) % 6]);
    }
}