#include <bits/stdc++.h>
using namespace std;

const int N = 4e6+5;
int phi[N], ans[N];

void phi_1_to_n()
{
    iota(phi, phi + N, 0);
    for (int i = 2; i < N; i++)
    {
        if(phi[i] == i)
        for (int j = i; j < N; j += i)
            phi[j] -= phi[j] / i;
    }
}
void precum()
{
    phi_1_to_n();
    for(int i = 2; i < N; i++)
    {
        (ans[i] += phi[i]) >>= 1;
        ans[i] += i - 1;
        for(int j = i + i; j < N; j += i)
            ans[j] += i * phi[j / i];
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precum();
    int t; cin >> t;
    while(t--)
    {
        int k;  cin >> k;
        cout << ans[4 * k + 1] << '\n';
    }
}