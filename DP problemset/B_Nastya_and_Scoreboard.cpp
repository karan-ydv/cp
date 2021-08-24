#include <bits/stdc++.h>
using namespace std;

bitset<7> seg[10];
const int N = 2002;
bool dp[N][N];
int8_t digit[N][N];

const string s[] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                    "1101011", "1101111", "1010010", "1111111", "1111011"};


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 10; i++) {
        seg[i] = bitset<7>(s[i]);
    }
    
    int n, k;   cin >> n >> k;
    int mn[n];  string str[n];
    bitset<7> A[n];

    for(int i = 1; i <= n; i++) cin >> str[n - i];
    for(int i = 0; i < n; i++)  A[i] = bitset<7>(str[i]);

    dp[0][0] = 1;
    for(int i = 0; i < n; i++)  if(true)    // symmetry purpose
    for(int j = 0; j <= k; j++) if(dp[i][j])
    for(int8_t d = 0; d < 10; d++) if((A[i] & seg[d]) == A[i])
    {
        int z = (seg[d].count() - A[i].count());
        if(j + z <= k)
        {
            dp[i + 1][j + z] = 1;
            digit[i + 1][j + z] = max(digit[i + 1][j + z], d);
        }
    }
    
    if(dp[n][k])
    for(int i = n; i > 0; i--)
    {
        cout << char('0' + digit[i][k]);
        k -= (seg[digit[i][k]].count() - A[i - 1].count());
    }
    else cout << "-1";
}