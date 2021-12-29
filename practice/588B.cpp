#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int ans = 1;
    for(int i = 2; i <= (int) sqrt(n); i++) {
        if(n % i == 0)
        {
            ans *= i;
            while(n % i == 0)
                n /= i;
        }
    }
    ans *= n;
    cout << ans;
}