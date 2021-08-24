#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int queries;
int query(int z)
{
    assert(queries > 0);
    queries--;
    cout << z << endl;
    int x; cin >> x;
    return x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, k;   cin >> n >> k;
        int z = 0, p = 0;
        queries = n;
        for(int x = 0; x <= n - 1; x++)
        {
            z = p ^ x;
            if(query(z))
                break;
            p ^= z;
        }
    }
}