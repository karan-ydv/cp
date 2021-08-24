#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[n];   for(int &x: a)  cin >> x;
        cout << "1\n";
        string b = "";
        stack<int> stack;
        stack.push(1);
        for(int i = 1; i < n; i++)
        {
            if(a[i] == 1)
            {
                b += to_string(stack.top()) + ".";
                stack.push(1);
                cout << b << a[i] << '\n';
            }
            else
            {
                while(a[i] != stack.top() + 1)
                {
                    stack.pop();
                    b.pop_back();
                    while(!b.empty() and b.back() != '.')
                        b.pop_back();
                }
                stack.pop();
                while(!b.empty() and b.back() != '.')
                    b.pop_back();
                cout << b << a[i] << '\n';
                stack.push(a[i]);
            }
        }
    }
}