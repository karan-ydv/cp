#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool commonSubstring(string& a, string &b)
{
    for(char c = 'a'; c <= 'z'; c++)
        if(a.find(c) != string::npos
        and b.find(c) != string::npos)
            return true;
    return false;
}

void commonSubstring(vector<string> a, vector<string> b)
{
    for(int i = 0; i < a.size(); i++)
    {
        if(commonSubstring(a[i], b[i]))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}