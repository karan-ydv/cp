#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int main()
{
    int t;  cin >> t;
    cout << t << '\n' << "1\n";
    while(t--)
    {
        int n;  cin >> n;
        for(int& x: a)  cin >> x;
		sort(a, a + n);
        cout << n << ' ';
        for(int x: a)   cout << x << ' ';
    }
}