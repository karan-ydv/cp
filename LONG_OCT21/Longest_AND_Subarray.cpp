#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, ans = 1;	cin >> n;
        for(int i = 2; i <= n; i <<= 1)
            ans = max(ans, min(2 * i, n + 1) - i);
        cout << ans << '\n';
    }
}