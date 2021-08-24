#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    string s;   cin >> s;
    int R, G, B;
    R = count(s.begin(), s.end(), 'R');
    G = count(s.begin(), s.end(), 'G');
    B = count(s.begin(), s.end(), 'B');

    pair<int, char> A[] = {{R, 'R'}, {G, 'G'}, {B, 'B'}};
    sort(A, A + 3);

    if(A[0].first > 0 or A[1].first > 1)
        cout << "BGR";
    else if(A[1].first == 0)
        cout << A[2].second;
    else
    {
        if(A[2].first == 1)   cout << A[0].second;
        else if(A[0].second < A[1].second)
            cout << A[0].second << A[1].second;
        else
            cout << A[1].second << A[0].second;
    }
}