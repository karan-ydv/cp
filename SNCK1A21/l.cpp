#include <bits/stdc++.h>
using namespace std;

const int p = 31, M = 1e9+9;
int mod_exp(int a, int n)
{
    int res = 1;
    for(; n; a = (long long) a * a % M, n >>= 1)
        if(n & 1) res = (long long) res * a % M;
    return res;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needle_hash = 0, p_pow = 1;
        for(char c: needle) {
            (needle_hash += (c - 'a') * p_pow % M) %= M;
            p_pow = (long long) p * p_pow % M;
        }
        return hashCheck(haystack, needle.length(), needle_hash);
    }
    int hashCheck(string &s, int L, int hash)
    {
        int n = s.length();
        int roll_hash = 0, p_pow = 1;
        for(int i = 0; i < L; i++) {
            (roll_hash += (s[i] - 'a') * p_pow % M) %= M;
            p_pow = (long long) p * p_pow % M;    
        }
        if(roll_hash == hash)   return 0;
        int pInv = mod_exp(p, M - 2), mInv = pInv;
        for(int i = L, p_pow2 = 1; i < s.length(); i++) {
            (roll_hash += (s[i] - 'a') * p_pow % M) %= M;
            (roll_hash += M - (s[i- L] - 'a') * p_pow2 % M) %= M;
            if((long long)roll_hash * mInv % M == hash)
                return i - L + 1;

            p_pow = (long long) p * p_pow % M;
            p_pow2 = (long long) p * p_pow2 % M;
            mInv = (long long) mInv * pInv % M;
        }
        return -1;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cout << Solution().strStr("abc", "c");
}