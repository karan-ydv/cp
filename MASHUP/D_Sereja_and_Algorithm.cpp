#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int x[N], y[N], z[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;   cin >> s;
    int n = s.length();
    s = "!" + s;
    for(int i = 1; i <= n; i++)
    {
        x[i] = x[i - 1] + (s[i] == 'x');
        y[i] = y[i - 1] + (s[i] == 'y');
        z[i] = z[i - 1] + (s[i] == 'z');
    }
    int m;  cin >> m;
    while(m--)
    {
        int l, r;   cin >> l >> r;
        int len = r - l + 1;
        if(len < 3)
        {
            cout << "YES\n";
            continue;
        }
        int xx = x[r] - x[l - 1];
        int yy = y[r] - y[l - 1];
        int zz = z[r] - z[l - 1];
        bool flag = false;
        if(len % 3 == 0)
        {
            flag = (xx == len / 3) and (yy == len / 3);
        }
        else if(len % 3 == 1)
        {
            flag |= (xx == len / 3) and (yy == len / 3);
            flag |= (xx == len / 3) and (zz == len / 3);
            flag |= (zz == len / 3) and (yy == len / 3);
        }
        else
        {
            flag |= (xx == len / 3 + 1) and (yy == len / 3 + 1);
            flag |= (xx == len / 3 + 1) and (zz == len / 3 + 1);
            flag |= (zz == len / 3 + 1) and (yy == len / 3 + 1);
        }
        flag ? cout << "YES\n" : cout << "NO\n";
    }
}