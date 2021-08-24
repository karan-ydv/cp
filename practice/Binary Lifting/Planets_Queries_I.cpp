#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
const int LOG = 31;
int lift[N][LOG];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;   cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> lift[i][0];
    
    for(int i = 1; i < LOG; i++)
    for(int j = 1; j <= n; j++)
        lift[j][i] = lift[lift[j][i - 1]][i - 1];

    while(q--)
    {
        int x, k;   cin >> x >> k;
        for(int i = 0, b = 1; i < LOG; i++, b <<= 1)
            if(k & b) x = lift[x][i];
        cout << x << '\n';
    }
}