#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 2e6+5;
int divs[N];
void calc()
{
    for(int i = 2; i < N; i++) if(!divs[i])
        for(int j = i; j < N; j += i) divs[j]++;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    calc();
    int t;  cin >> t;
    while (t--)
    {
        int n, m;   cin >> n >> m;
        if(n > m)   swap(n, m);
        int ans = 0;
        for(int i = 1; i < n; i++)
            ans += i * (divs[i + 1] + divs[n + m - i + 1]);
        for(int i = n + 1; i <= m + 1; i++)
            ans += n * divs[i];
        cout << ans << '\n';
    }
}