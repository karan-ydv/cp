#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >>n;
    bitset<64> b(n);
    string s = b.to_string();
    reverse(s.begin(), s.end());
    while(s.back() == '0')
        s.pop_back();
    s.pop_back();
    reverse(s.begin(), s.end());
    cout << 'A';
    // cerr << s << '\n';
    for(char &c: s)
    {
        cout << 'B';
        if(c == '1')
            cout << 'A';
    }
}