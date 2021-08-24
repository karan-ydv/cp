#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void same(string s)
{
    for(int i = 1; i < 4; i++)
        if(s[i] != s[0])    return;
    cout << "Weak";
    exit(0);
}
void follows(string s)
{
    for(int i = 1; i < 4; i++)
        if((s[i - 1] - '0' + 1) % 10 != (s[i] - '0'))    return;
    cout << "Weak";
    exit(0);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;   cin >> s;
    same(s);
    follows(s);
    cout << "Strong";
}