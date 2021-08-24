#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  string s;
    cin >> n >> s;
    int i = s.find('1');
    if(i & 1)
        cout << "Aoki";
    else
        cout << "Takahashi";
}