#include <bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
int T,n,k;
int a[8005],c[8005],f[8005];

void solve(){
    int ans=inf;
    cin >>n;
    //vector <int> f[n+1];
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=n;i++) cin >>c[i];
    for(int i=1;i<=n;i++){
        f[i]=inf;
    }
    f[1]=0;
    f[0]=c[1];
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<=a[i]) f[i]=min(f[i],f[j]);
            f[j]+=c[i];
            
        }
    }
    for(int i=1;i<=n;i++) ans=min(ans,f[i]);
    //for(int i=1;i<=n;i++) f[i].clear();
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}