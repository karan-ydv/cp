#include <bits/stdc++.h>
using namespace std;

bool bob(int n)
{
    for(int i = 2; i * i <= n; i++)
    if(n % i == 0)  return i;
    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        if(bob(n) & 1)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
}