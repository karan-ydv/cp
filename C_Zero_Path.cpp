#include <iostream>
#include <vector>
#define int int64_t
using namespace std;

const int N = 1e3+5;
int a[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, m;   cin >> n >> m;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
        
        vector<bitset<4*N>> v(m + 1);

        for(int i = 1; i <= n; i++)
        for (int j = 1; j <= m; i++) 
        {
            v[i][j] = 
        }
    }
}