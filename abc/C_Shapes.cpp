#include <bits/stdc++.h>
using namespace std;

const int N = 202;
string s[N], t[N];
int n, cnt;

void rotate()
{
    for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++)
        swap(s[i][j], s[j][i]);
    
    for(int i = 0; i < n; i++)
        reverse(s[i].begin(), s[i].end());    
}

pair<int, int> topleft(string a[])
{
    int x = 0, y = 0;
    for(int i = 0, j; i < n; i++) {
        for(j = 0; j < n; j++)
        if(a[i][j] == '#') {
            x = i; break;
        }
        if(j < n)   break;
    }

    for(int i, j = 0; j < n; j++) {
        for(i = 0; i < n; i++)
        if(a[i][j] == '#') {
            y = j; break;
        }
        if(i < n)   break;
    }

    return {x, y};
}

bool match()
{
    auto [x, y] = topleft(s);
    auto [p, q] = topleft(t);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    if(s[(x + i) % n][(y + j) % n] != t[(p + i) % n][(q + j) % n])
        return false;
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        cnt += (int) count(s[i].begin(), s[i].end(), '#');
    }

    for(int i = 0; i < n; i++) {
        cin >> t[i];
        cnt -= (int) count(t[i].begin(), t[i].end(), '#');
    }

    if(cnt != 0)
        return cout << "No", 0;
    
    bool flag = match();
    for(int _ = 1; !flag and _ < 4; _++)
    {
        rotate();
        flag = match();
    }

    flag ? cout << "Yes" : cout << "No";
}