#include <bits/stdc++.h>
using namespace std;

int fun(string s1, string s2, string s3)
{
    string c1 = "AAA", c2 = "AAA", c3 = "AAA", d1 = "AAA", d2 = "AAA";
    c1[0] = s1[0], c1[1] = s2[0], c1[2] = s3[0];
    c2[0] = s1[1], c2[1] = s2[1], c2[2] = s3[1];
    c3[0] = s1[2], c3[1] = s2[2], c3[2] = s3[2];
    d1[0] = s1[0], d1[1] = s2[1], d1[2] = s3[2];
    d2[0] = s3[0], d2[1] = s2[1], d2[2] = s1[2];
    
    // cout << d1 << '\n' << d2 << '\n';
    int x = count(s1.begin(), s1.end(), 'X') +
            count(s2.begin(), s2.end(), 'X') +
            count(s3.begin(), s3.end(), 'X');
    int o = count(s1.begin(), s1.end(), 'O') +
            count(s2.begin(), s2.end(), 'O') +
            count(s3.begin(), s3.end(), 'O');
    int blank =   count(s1.begin(), s1.end(), '_') +
                count(s2.begin(), s2.end(), '_') +
                count(s3.begin(), s3.end(), '_');
    if(x + o + blank != 9)
    {
        return 3;   //cout << "no\n";
    }
    if( s1 == "OOO" or s2 == "OOO" or s3 == "OOO" or
        c1 == "OOO" or c2 == "OOO" or c3 == "OOO" or
        d1 == "OOO" or d2 == "OOO")
    {
        if(x != o)  return 3;   //cout << "no\n";
        else if( s1 == "XXX" or s2 == "XXX" or s3 == "XXX" or
                 c1 == "XXX" or c2 == "XXX" or c3 == "XXX" or
                 d1 == "XXX" or d2 == "XXX" )
                return 3;   //cout << "no\n";
        else    return 1;    //cout << "yes\n";
    }
    else if( s1 == "XXX" or s2 == "XXX" or s3 == "XXX" or
             c1 == "XXX" or c2 == "XXX" or c3 == "XXX" or
             d1 == "XXX" or d2 == "XXX" )
    {
        if(x != o + 1)  return 3;    //cout << "no\n";
        else if( s1 == "OOO" or s2 == "OOO" or s3 == "OOO" or
                 c1 == "OOO" or c2 == "OOO" or c3 == "OOO" or
                 d1 == "OOO" or d2 == "OOO" )
                return 3;   //cout << "no\n";
        else    return 1;    //cout << "yes\n";
    }
    else
    {
        if(x == o or x == o + 1)
        {
            if(blank == 0)  return 1;    //cout << "yes\n";
            else            return 2;
        }
        else    return 3;   //cout << "no\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        cout << fun(s1, s2, s3) << '\n';
    }
}