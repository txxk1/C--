#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200005],t[4];
void solve(){
    int ans=0;
    cin >>n;
    t[0]=0;
    t[1]=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    a[n+1]=0;
    for(int i=2;i<=n;i+=2){
        if(a[i]<a[i-1]+a[i+1]){
            ans+=a[i+1]+a[i-1]-a[i];
            if(a[i]<a[i-1]){
                a[i+1]=0;
                a[i-1]=a[i];
            }
            else a[i+1]=a[i]-a[i-1];
        }
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}