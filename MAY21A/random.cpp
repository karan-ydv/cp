#include <bits/stdc++.h>
#define int int64_t
using namespace std;

string gen_random(const int len) {
    
    string tmp_s;
    static const char alphanum[] =
        "01";
    
    srand( (unsigned) time(NULL) * getpid());

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    
    
    return tmp_s;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));
    int a = rand() % 15 + 1;
    int b = rand() % 15 + 1;
    cout << gen_random(a) << '\n';
    cout << gen_random(b);
}