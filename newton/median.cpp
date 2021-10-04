#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a[3];
    for(int &x: a)   cin >> x;
    sort(a, a + 3);
    cout << a[1] << '\n';
}