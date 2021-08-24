#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2, s3;  cin >> s1 >> s2 >> s3;
    if(s3.length() < max(s1.length(), s2.length()))
        return cout << "UNSOLVABLE", 0;
    
    set<int_fast8_t> set;
    vector<int_fast8_t> S1, S2, S3;
    for(char c: s1) set.insert(c - 'a'), S1.push_back(c - 'a');
    for(char c: s2) set.insert(c - 'a'), S2.push_back(c - 'a');
    for(char c: s3) set.insert(c - 'a'), S3.push_back(c - 'a');
    if(set.size() > 10) return cout << "UNSOLVABLE", 0;
   
    int_fast8_t idx[26], i = 0;
    for(auto c: set)    idx[c] = i++;

    int_fast8_t a[10];
    iota(a, a + 10, 0);
    do
    {
        if(a[idx[S1[0]]] == 0 or a[idx[S2[0]]] == 0 or a[idx[S3[0]]] == 0)
            continue;
        int_fast64_t n1 = 0, n2 = 0, n3 = 0;
        for(auto c: S1)    n1 *= 10, n1 += a[idx[c]];
        for(auto c: S2)    n2 *= 10, n2 += a[idx[c]];
        for(auto c: S3)    n3 *= 10, n3 += a[idx[c]];
        if(n1 + n2 == n3)
        {
            cout << n1 << '\n';
            cout << n2 << '\n';
            cout << n3 << '\n';
            return 0;
        }
    } while (next_permutation(a, a + 10));
    cout << "UNSOLVABLE";
}