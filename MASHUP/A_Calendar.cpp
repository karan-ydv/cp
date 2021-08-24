#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> parsedate(string s)
{
    int y, m, d;
    y = stoi(s.substr(0, 4));
    m = stoi(s.substr(5, 2));
    d = stoi(s.substr(8, 2));
    // cerr << y << ' ' << m << ' ' << d << endl;
    return {y, m, d};
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string d1, d2;
    cin >> d1 >> d2;
    if(d2 < d1) swap(d1, d2);
    auto [yy1, mm1, dd1] = parsedate(d1);
    auto [yy2, mm2, dd2] = parsedate(d2);

    int ans = 0;
    for(int i = yy1; i <= yy2; i++)
    {
        int mbeg = (i == yy1 ? mm1 : 1);
        int mend = (i == yy2 ? mm2 : 12);
        for(int j = mbeg; j <= mend; j++)
        {
            int dbeg, dend;
            if(i == yy1 and j == mm1)
                dbeg = dd1;
            else
                dbeg = 1;
            
            if(i == yy2 and j == mm2)
                dend = dd2 - 1;
            else
            {
                if(j == 2)
                    dend = ((i % 400 == 0) or (i % 4 == 0 && i % 100 != 0)) ? 29 : 28;
                else
                    dend = (j == 1 or j == 3 or j == 5 or j == 7 or j == 8 or j == 10 or j == 12) ? 31 : 30;
            }
            ans += dend - dbeg + 1;
        }
    }
    cout << ans;
}