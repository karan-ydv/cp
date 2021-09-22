#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int A[N];

void solve(int n)
{
    unordered_map<int, int> mp, rev;
    int a, b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        mp[a] = b;
        rev[b] = a;
    }
    for(auto p: mp)
    if(rev.find(p.first) == rev.end())
    {
        a = p.first;
        break;
    }
    A[0] = a;
    A[1] = mp[0];
    for(int i = 2; i < n; i ++)
        A[i] = mp[A[i - 2]];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    solve(n);
    for(int i = 0; i < n; i++)
        cout << A[i] << ' ';
}