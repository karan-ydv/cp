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
        int A[n];   for(int &x: A)  cin >> x;
        int P[n];   for(int &x: P)  cin >> x;
        int q;  cin >> q;
        while(q--)
        {
            int typ;    cin >> typ;
            if(typ == 1)
            {

            }
            else if(typ == 2)
            {
                int x, y;   cin >> x >> y;
                x--, y--;
            }
            else
            {
                int x;  cin >> x;
            }
        }
    }
}