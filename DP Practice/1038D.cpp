#include <bits/stdc++.h>
using namespace std;

long long sum = 0;
const int N = 5e5+5;
int a[N], n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i); sum += a[i];
    }
    
    if(n == 1)
        return printf("%d", a[0]), 0;

    int mx = *max_element(a, a + n);
    int mn = *min_element(a, a + n);

    if(all_of(a, a + n, [](int x){ return x >= 0; }))
        return printf("%lld", sum - 2 * mn), 0;
    
    if(all_of(a, a + n, [](int x){ return x < 0; }))
        return printf("%lld", 2 * mx - sum), 0;
    
    long long ans = 0;
    for(int i = 0; i < n; i++)
        ans += abs(a[i]);

    printf("%lld", ans);
}