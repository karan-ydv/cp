#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    string s = "", v = "";
    for (int i = 0; i < a.length();)
    {
        if (a[i] == 'o')
            s += '1', i += 3;
        else
        {
            if (s.length())
                s += '0';
            i += 4;
        }
    }
    for (int i = 0; i < b.length();)
    {
        if (b[i] == 'o')
            v += '1', i += 3;
        else
        {
            if (v.length())
                v += '0';
            i += 4;
        }
    }
    if (s.length() < v.length())
        cout << '<';
    else if (s.length() > v.length())
        cout << '>';
    else
    {
        if (s == v)
            cout << '=';
        else if (s < v)
            cout << '<';
        else
            cout << '>';
    }
}