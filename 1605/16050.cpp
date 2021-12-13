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
        int a, b, c;
        cin >> a >> b >> c;
        if(abs(a + c - 2 * b) % 3)
            cout << "1\n";
        else
            cout << "0\n";
    }
}