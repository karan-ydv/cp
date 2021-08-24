#include <iostream>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;   cin >> n >> m;
    int ans = ((1 << n) ^ (1 << m)) | ((2 << n) & (2 << m));
    cout << ans;
}