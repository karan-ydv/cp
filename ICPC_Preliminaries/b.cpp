#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
int GetIndicesSum(int N,vector<int> A,int Q,vector<int> X,vector<int> L,vector<int> R){
    int sum = 0;
    for(int i = 0; i < Q; i++) {
        pair<int, int> p = {1 << 30, 0};
        for(int j = L[i] - 1; j < R[i]; j++) {
            p = min(p, {X[i] ^ A[j], j + 1});
        }
        auto [a, b] = p;
        sum = (sum + b) % mod;
    }
    return sum;
}
int32_t main(){ 
    int N;
    cin>>N;
    vector<int> A(N);
    for(int j = 0;j < N;j++){
        cin>>A[j];
    }
    int Q;
    cin>>Q;
    vector<int> X(Q);
    for(int j = 0;j < Q;j++){
        cin>>X[j];
    }
    vector<int> L(Q);
    for(int j = 0;j < Q;j++){
        cin>>L[j];
    }
    vector<int> R(Q);
    for(int j = 0;j < Q;j++){
        cin>>R[j];
    }
    int result;
    result = GetIndicesSum(N,A,Q,X,L,R);
    cout<<result;
    return 0;
}