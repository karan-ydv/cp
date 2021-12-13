#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long r, g, b;    cin >> r >> g >> b;
    cout << min({r + g, g + b, r + b, (r + g + b) / 3});
}