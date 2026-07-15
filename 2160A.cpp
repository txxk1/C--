#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,T,t[203];
void solve(){
    cin >>n;
    for(int i=0;i<=100;i++) t[i]=0;
    for(int i=1;i<=n;i++){
        int x;
        cin >>x;
        t[x]++;
    }
    for(int i=0;i<=100;i++){
        if(t[i]==0){
            cout <<i<<endl;
            return ;
        }
    }
}
signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}