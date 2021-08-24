#include <bits/stdc++.h>
using namespace std;

int queries;
bool query(int z)
{
    assert(queries > 0);
    queries--;
    cout << z << endl;
    int x; cin >> x;
    if(x == -1)
        exit(1);
    return x;
}

int add(int &a, int b, int k)
{
    int res = 0;
    for(int p = 1; a or b; p *= k) {
        res += (a % k + b % k) % k * p;
        a /= k, b /= k;
    }
    return res;
}
int subtract(int a, int b, int k)
{
    int res = 0;
    for(int p = 1; a or b; p *= k) {
        res += (a % k + k - b % k) % k * p;
        a /= k, b /= k;
    }
    return res;
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
        for(int x = 0; ; x++)
        {
            z = add(z, x, k);
            if(query(z))
                break;
            p = subtract(p, z, k);
        }
    }
}