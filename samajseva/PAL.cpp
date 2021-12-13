#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s) {
    int n = s.length();
    for(int i = 0; i < n / 2; i++) {
        if(s[i] != s[n - 1 - i])
            return false;
    }
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x;  cin >> x;
    int ans;
    for(int i = 1; ; i++) {
        if(palindrome(to_string(i)))
        {
            ans = x;
            if(i > N)   break;
        }
    }
    cout << ans;
}