#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; string s;
    cin >> n >> s;
    cout << unique(s.begin(), s.end()) - s.begin();
}