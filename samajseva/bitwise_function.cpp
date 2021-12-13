#include <bits/stdc++.h>
using namespace std;

long long solve(int N, int X, int Y, vector<int> A, vector<int> B)
{
    int Z = 0;
    for(int b = 1; b < 20; b <<= 1)
    if((X & b) == (Y & b))  Z |= b;

    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        
    }
}