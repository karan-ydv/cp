#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
string s;   int n;

int pi[N];   //  prefix function of string s
int f[N];   //  number of occurances of prefix i

// kmp algorithm
void precal()
{
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    for (int i = 0; i < n; i++)
        f[pi[i]]++;
    for (int i = n-1; i > 0; i--)
        f[pi[i-1]] += f[i];
    for (int i = 0; i <= n; i++)
        ++f[i];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.length();
    precal();
    
    int i = pi[n - 1];
    
    while(i > 0 and f[i] < 3) 
        i = pi[i - 1];

    if(i == 0)
        cout << "Just a legend";
    else
        cout << s.substr(0, i);
}