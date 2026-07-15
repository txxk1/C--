#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,l,r,k,t[61];
int f(int x){
    return x*x;
}
void solve(){
    cin >>n>>l>>r>>k;
    if(n%2==1){
        cout <<l<<endl;
        return ;
    }
    if(n==2){
        cout <<-1<<endl;
        return ;
    }
    for(int i=0;i<=60;i++){
        if(l<t[i]&&t[i]<=r){
            if(k<=n-2) cout <<l<<endl;
            else cout <<t[i]<<endl;
            return ;
        }
    }
    cout <<-1<<endl;
    return ;
}
signed main(){
    t[0]=1ll;
    for(int i=1;i<=60;i++) t[i]=t[i-1]*2ll;
    cin >>T;
    while(T--) solve();
    return 0;
}
// maxn>minn+d
// 00 0 0
// 01 0 1
// 11 1 0