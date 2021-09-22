// #include <bits/stdc++.h>
// #define int int64_t
// using namespace std;

// int32_t main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     vector<int> set = {1, 22};

//     function<void(int, int, vector<int>)> f =
//     [&](int i, int s, vector<int> v)
//     {
//         if(s == 0)
//         {
//             int n = v.size();
//             for(int i = 0; i < n; i++)
//             for(int j = 1; j < v[i]; j++)
//                 v.emplace_back(v[i]);
//             sort(v.begin(), v.end());
//             do
//             {
//                 int k = 0;
//                 for(int x: v)
//                     (k *= 10) += x;
//                 set.emplace_back(k);
//             } while (next_permutation(v.begin(), v.end()));
//             return;
//         }
//         if(i > 9 or i > s)  return;
//         f(i + 1, s, v);
//         v.emplace_back(i);
//         f(i + 1, s - i, v);
//     };
    
//     for(int i = 3; i < 14; i++) f(1, i, {});

//     sort(set.begin(), set.end());
//     int t;	cin >> t;
//     while(t--)
//     {
//         int n;	cin >> n;
//         cout << *upper_bound(set.begin(), set.end(), n) << '\n';
//     }
// }

#include<bits/stdc++.h>
using namespace std;

vector<long long> Set;

long long beautifulNumber (long long N) {
   // Write your code here
   return *upper_bound(Set.begin(), Set.end(), N);
}

void fun(int i, int s, vector<int> v) {
    if(i == 10)
    {
        if(s > 13)  return;
        int k = v.size();
        for(int i = 0; i < k; i++)
            for(int j = 1; j < v[i]; j++)
                v.emplace_back(v[i]);
        sort(v.begin(), v.end());
        do
        {
            long long n = 0;
            for(int x: v)
                (n *= 10) += x;
            Set.emplace_back(n);
        } while(next_permutation(v.begin(), v.end()));
    }
    fun(i + 1, s, v);
    v.emplace_back(i);
    fun(i + 1, s + i, v);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    fun(1, 0, {});
    sort(Set.begin(), Set.end());
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        long long N;
        cin >> N;

        long long out_;
        out_ = beautifulNumber(N);
        cout << out_;
        cout << "\n";
    }
}