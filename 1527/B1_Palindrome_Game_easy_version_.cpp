#include <bits/stdc++.h>
using namespace std;

bool palindrome(string &s) {
    int n = s.length();
    for(int i = 0; i < n / 2; i++)
        if(s[i] != s[n - 1 - i])    return false;
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        string s;   cin >> s;
        int c = count(s.begin(), s.end(), '0');
        
        string ans;
        if(palindrome(s))
        {
            ans = "BOB";
            if(c & 1)
            {
                if(c - 1 > 0)   ans = "ALICE";
            }

        }
        else
        {
            
        }
        cout << ans << '\n';
    }
}