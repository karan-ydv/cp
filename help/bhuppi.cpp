#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int magicalStringCount(char *str)
{
    int n = 0;  while(str[n] != '\0') n++;
    unordered_set<string> set;
    for(int i = 0; i < n; i++) {
        string x = "";
        for(int j = i; j < n; j++) {
            x += str[j];
            set.insert(x);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        string x = "";
        for(int j = i; j >= 0; j--) {
            x += str[j];
            ans += set.count(x);
        }
    }
    cout << ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char *str[20];
    scanf("%s", str);
    cout << magicalStringCount(str);
}