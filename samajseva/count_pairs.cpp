#include <bits/stdc++.h>
using namespace std;

long long count_pairs(int N, vector<int> A, int X)
{
    map<int, vector<int>> mp;
    for(int i = 0; i < N; i++)
        mp[A[i]].emplace_back(i + 1);
        
    long long ans = 0;
    for(auto &[_, v]: mp)
    {
        
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;   cin >> n >> x;
    vector<int>
}