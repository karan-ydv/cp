#include <bits/stdc++.h>
using namespace std;

int A[200];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n; int a[n];
    for(int &x: a)  cin >> x;

    pair<int, int> ans = {-1, -1};
    for(int i = 1; i <= min(200.0, pow(2, n) - 1); i++)
    {
        bitset<10> b(i);
        int s = 0;
        for(int j = 0; j < min(10, n); j++)
            if(b[j]) (s += a[j]) %= 200;
        
        if(A[s] != 0)
        {
            ans = {A[s], i};
            break;
        }
        A[s] = i;
    }

    if(ans.first == -1) return cout << "No\n", 0;
    bitset<10> x(ans.first);
    bitset<10> y(ans.second);
    cout << "Yes\n";
    cout << x.count() << ' ';
    for(int i = 0; i < 10; i++) if(x[i])    cout << i + 1 << ' '; cout << '\n';
    cout << y.count() << ' ';
    for(int i = 0; i < 10; i++) if(y[i])    cout << i + 1 << ' '; cout << '\n';
}