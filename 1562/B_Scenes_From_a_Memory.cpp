#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool prime(int n)
{
    if(n == 1)	return false;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0)	return false;
    }
    return true;
}

const int N = 1000;
bool p[N];

void calc(){
    for(int i = 1; i < N; i++) {
        p[i] = prime(i);
    }
}
void solve()
{
    int K; string s;
    cin >> K >> s;
    for(char c: s)
    if(!p[c - '0'])
    {
        cout << "1\n" << c << '\n';
        return;
    }

    for(int i = 0; i < K; i++)
    for(int j = i + 1; j < K; j++)
    {
        int x = (s[i] - '0') * 10 + s[j] - '0';
        if(!p[x])
        {
            cout << "2\n" << x << '\n';
            return;
        }
    }

    for(int i = 0; i < K; i++)
    for(int j = i + 1; j < K; j++)
    for(int k = j + 1; k < K; k++)
    {
        int x = (s[i] - '0') * 100 + (s[j] - '0') * 10 + s[k] - '0';
        if(!p[x])
        {
            cout << "3\n" << x << '\n';
            return;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    calc();
    int t;	cin >> t;
    while(t--)
    {
        solve();
    }
}   