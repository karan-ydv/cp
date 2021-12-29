#include <iostream>
using namespace std;

int main()
{
    int n, b; cin >> n >> b;
    long long ans = (n + 1) / 2;
    ans *= b;
    cout << ans;
}