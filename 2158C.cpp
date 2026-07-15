#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[200005],b[200005],f[200005][2];
void solve(){
    int ans=-1e18,now=0,cnt=0;
    cin >>n>>k;
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=n;i++) cin >>b[i];
    for(int i=1;i<=n;i++) f[i][0]=0,f[i][1]=0;
    if(k%2==0){
        
        for(int i=1;i<=n;i++){
            f[i][0]=max(a[i],f[i-1][0]+a[i]);
            ans=max(ans,f[i][0]);
        }
        
        cout <<ans<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            f[i][0]=max(a[i],f[i-1][0]+a[i]);
            f[i][1]=max(f[i-1][1]+a[i],max(a[i]+b[i],f[i-1][0]+a[i]+b[i]));
            ans=max(ans,f[i][1]);
        }
        cout <<ans<<endl;
    }
    return ;
    //
}
//
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
