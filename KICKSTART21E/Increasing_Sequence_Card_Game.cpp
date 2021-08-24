#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    double ans[11];
    int a[10];
    iota(a, a + 10, 1);
    for(int i = 1, f = 1; i <= 10; i++) {
        f *= i;
        int c = f;
        sort(a, a + 10);
        do
        {
            int prev = a[0];
            for(int j = 1; j < i; j++) if(a[j] > prev)
            {
                prev = a[j];
                c++;
            }
        } while (next_permutation(a, a + i));
        ans[i] = 1.0 * c / f;
    }
    cout << fixed << setprecision(10);
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        int n;  cin >> n;
        cout << ans[n] << '\n';
    }
}