#include <bits/stdc++.h>
using namespace std;

const int X = 1e8;
int A[105], coins;

int query(int i, int j)
{
    assert(i < j);
    coins += (X + j - i) / j - i + 1;
    assert(coins <= 6e8);
    cout << "M " << i << ' ' << j << endl;
    int x;  cin >> x;
    assert(x != -1);
    return x;
}
int swap(int i, int j)
{
    cout << "S " << i << ' ' << j << endl;
    int x;  cin >> x;
    assert(x != -1);
    return x;
}
void output()
{
    cout << "D" << endl;
    int x;  cin >> x;
    assert(x != -1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;	cin >> t >> n;
    for(int _ = 1; _ <= t; _ ++) {
        coins = 0;
        for(int i = 1; i < n; i++)
        {
            int x = query(i, n);
            if(i != x) swap(i, x);
        }
        output();
    }
}