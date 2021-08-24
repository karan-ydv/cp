#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool fun()
{
    string s;
    int n, j;   cin >> n >> j >> s;
    s = "!" + s;
    for(int i = 1; i < j; i++)
    {
        if(j == n)
            return true;
        
        if(s[j + 1] == '#')
            s[j + 1] = '.';
        else
            j += 1;
    }
    return false;
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        if(fun())
            cout << "JAY\n";
        else
            cout << "JEFF\n";
    }
}