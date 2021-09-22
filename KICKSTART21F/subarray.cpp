#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;      cin >> n;
    int a[n];   for(int &x: a)  cin >> x;

    set<int> set;
    for(int i = 0; i < n; i++)
    {
        for(int j = i, x = 0; j < n; j++)
        {
            x |= a[j];
            set.insert(x);
        }
    }
    cout << set.size() << '\n';
    for(int x: set) cout << x << ' ';
}