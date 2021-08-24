#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, p;
    cin >> n >> k >> p;
    int a[n];
    for (int &x : a)
        cin >> x;
    int ans = *min_element(a, a + n) + p;
    cout << ans;
}