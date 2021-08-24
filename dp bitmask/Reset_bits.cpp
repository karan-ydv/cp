#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned int n,  k;  cin >> n >> k;
    unsigned z = unsigned(0) - 1;
    n &= z << k;
    cout << n;
}