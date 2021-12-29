#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool rabin_karp1(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    long long h_s = 0, h_t = 0; 
    for (int i = 0; i < S; i++) 
        h_t = (h_t + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 
    return h_t == h_s;
}

int rabin_karp2(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    int occurences = 0;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences ++;
    }
    return occurences;
}

int prefix_function(const string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi.back();
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        string a, b; int k;
        cin >> k >> a >> b;
        int n = a.length();
        int m = b.length();

        auto fun = [&](int p)
        {
            string x = a.substr(0, p);
            return rabin_karp2(x, b) >= k;
        };

        int beg = 1, end = min(n, m);
        int ans = 0;

        while(beg <= end)
        {
            int mid = (beg + end) >> 1;
            if(fun(mid))
                beg = mid + 1, ans = mid;
            else
                end = mid - 1;
        }

        if(ans < n)
        {
            ans = min(ans, prefix_function(a));
        }

        if(ans == 0)
            cout << "No Plagiarism\n";
        else
            cout << a.substr(0, ans) << '\n';
    }
}