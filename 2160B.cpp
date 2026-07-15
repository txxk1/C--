#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,T,a[100003],ans[100003];
void solve(){
    cin >>n;
    //for(int i=0;i<=100;i++) t[i]=0;
    int now=1;
    cin >>a[1];
    ans[1]=1;
    for(int i=2;i<=n;i++){
        cin >>a[i];
        if(a[i]==a[i-1]+i) ans[i]=i;
        else{
            ans[i]=ans[i-a[i]+a[i-1]];
        }
    }
    for(int i=1;i<=n;i++){
        cout <<ans[i]<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}