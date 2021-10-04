#include <bits/stdc++.h>
using namespace std;

string solution(string &message, int k)
{
    if(message.length() <= k)   return message;
    cerr << message[k];
    while(k >= 0 and message[k] != ' ') k--;
    while(k > 0 and message[k - 1] == ' ') k--;
    return message.substr(0, max(0, k));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    cout << solution(s, 14);
}