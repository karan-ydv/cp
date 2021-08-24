#include <iostream>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned int n;  cin >> n;
    int fenwick = 1 << __builtin_ctz(n);
    cout << fenwick;
}