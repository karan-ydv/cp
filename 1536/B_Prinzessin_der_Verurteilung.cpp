#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct KMP
{
    int n; string s;
    vector<int> pi;
    KMP(string x)
    {
        x = s;
        n = x.length();
        pi.resize(n);
        for (int i = 1; i < n; i++)
        {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            pi[i] = j + (s[i] == s[j]);
        }
    }
    bool substr(const string &str)
    {
        int m = str.length(), j = 0;
        for(int i = 0; i < n; )
        {
            if(s[i] != str[j])
            {
                if(j == 0)  i++;
                else        j = pi[j - 1];
            }
            else i++, j++;
            if(j == m)  return true;
        }
        return false;
    }
};

string base26(int n)
{
    string s = "";
    if(n < 26)
        s += char('a' + n);
    else
    {
        s += base26(n / 26 - 1);
        s += base26(n % 26);
    }
    return s;
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n; string s;
        cin >> n >> s;
        string ans;
        KMP kmp(s);
        for(int i = 0; ; i++)
        {
            string x = base26(i);
            if(!kmp.substr(x))
            {
                ans = x;
                break;
            }
        }
        cout << ans << '\n';
    }
}