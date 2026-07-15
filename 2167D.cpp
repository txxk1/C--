#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[200005],t[2];
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
void solve(){
    int ans=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        ans=gcd(ans,a[i]);
    }
    for(int i=2;i<=60;i++){
        if(gcd(ans,i)==1){
            cout <<i<<endl;
            return ;
        }
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}