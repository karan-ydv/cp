#include <bits/stdc++.h>
using namespace std;

int64_t n, s, t, z, c;

int main()
{
    cin >> n;
    int a[n];   for(int &x: a)  cin >> x, s += x;
    sort(a, a + n);
    for(int x: a)
    {
        s -= x;
        t += x;
        c++;
        z += s - x * n + 2 * x * c - t;
    }
    cout << z / 2;
}