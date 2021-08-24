#include<bits/stdc++.h>
using namespace std;

#define MAX  4000001
int phi[MAX+1];
int ans[MAX+1];

void compute()
{
    for (int i = 1; i <= MAX; i++)
        phi[i] = i;

    for (int i = 2; i <= MAX; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= MAX; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    
    for(int i=3;i<=MAX; i+=2)
    {   int c=2*i;
         for(int j=i+c;j<=MAX;j+=c)
                ans[j]+= i*phi[j/i];
    }

}
void phi_1_to_n() {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i < N; i++)
        phi[i] = i;

    for (int i = 2; i < N; i++) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

int ans[N];
void precumpute()
{
    phi_1_to_n();
    for(int i = 1; i < N; i++)
    {
        for(int j = i; j < N; j += i)
        {
            if(i == 1)
            {
                ans[j] += i * (phi[j / i] / 2 - 1);
            }
            else if(i == j)
                ans[j] += j;
            else
                ans[j] += i * phi[j / i] / 2;
        }
    }
}
     
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    compute();
    int t;  
    cin >> t;
    for(int _ = 0; _ < t; _++)
    {
         int k;
        cin>>k;
        int a=4*k+1;
        int c= ans[a];
        c+=phi[a];
        c=c/2;
        c-=1;
        c+=a;
        cout<<c<<endl;
    }
}