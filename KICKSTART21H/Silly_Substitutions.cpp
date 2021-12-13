#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        int n; string s;
        cin >> n >> s;
        list<char> lst;
        for(char c: s)
            lst.push_back(c);
        bool flag = true;
        while(flag)
        {
            flag = false;
            for(char d = '0'; d <= '9'; d++)
            {
                char e = char('0' + (1 + d - '0') % 10);
                char f = char('0' + (1 + e - '0') % 10);
                for(auto itr = lst.begin(); next(itr) != lst.end(); )
                {
                    if(*itr == d and *next(itr) == e)
                    {
                        *itr = f;
                        lst.erase(next(itr));
                        flag = true;
                    }
                    itr++;
                }
            }
        }
        for(char c: lst) cout << c;
        cout << '\n';
    }
}