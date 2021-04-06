#include <iostream>

using namespace std;

void function(string &s, string &ans, int i)
{
    if(i == s.length())  return;
    if(s[i] != ans.back()) {
        ans += s[i];
    }
    function(s, ans, i + 1);
}

int main()
{
    string s="aabbccdda", ans = "";
    function(s, ans, 0);
    cout<<ans<<endl;
    return 0;
}