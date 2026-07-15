#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a,b;
int v[300005];

void solve(){
    cin >>n>>a;
    for(int i=1;i<=n;i++) cin >>v[i];
    int k=0,s=0;

    for(int i=1;i<=n;i++){
        if(v[i]<a) k++;
        if(v[i]>a) s++;
    }
    if(k>s) cout <<a-1<<endl;
    if(k==s) cout <<a<<endl;
    if(k<s) cout <<a+1<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
//  xi a xk
//  