#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool fun()
{
    int n;	cin >> n;
    n <<= 1;
    int a[n];   for(int &x: a)  cin >> x;
    sort(a, a + n);
    int avg = a[0] + a[n - 1];
    int l = 0, r = n - 1;
    while(l < r)
    {
        if(a[l] + a[r] != avg)
            return false;
        l++;
        r--;
    }
    return true;    
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        if(fun())
            cout << "PERFECT\n";
        else
            cout << "IMBALANCED\N"; 
    }
}