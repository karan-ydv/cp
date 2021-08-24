#include <iostream>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  
    cin >> n;
    n &= n - 1;
    cout << n;
}