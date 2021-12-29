#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    uint32_t a, b;
    while(cin >> a >> b)
    {
        cout << (a ^ b) << '\n';
    }
}