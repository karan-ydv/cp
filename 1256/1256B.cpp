#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve(int a[], int n)
{
    int c = n;
    for(int i = 0; i < n; ) {
        int j = min_element(a + i, a + min(i + c, n)) - a;
        int k = j;
        while(j > i)
        {
            swap(a[j], a[j - 1]);
            c--, j--;
        }
        if(k == i) i++;
        else       i = k;
        // for(int j = 0; j < n; j++)
        //     clog << a[j] << ' ';
        // clog << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[n];   for(int &x: a)  cin >> x;
        solve(a, n);
        for(int x: a)   cout << x << ' ';
        cout << '\n';
    }
}