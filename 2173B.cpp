#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[100005],b[100005],f[100005][2];
void solve(){
    int sum=0;
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=n;i++) cin >>b[i];
    f[1][0]=min(-a[1],b[1]);
    f[1][1]=max(-a[1],b[1]);
    for(int i=2;i<=n;i++){
        f[i][0]=min(f[i-1][0]-a[i],b[i]-f[i-1][1]);
        f[i][1]=max(f[i-1][1]-a[i],b[i]-f[i-1][0]);
    }
    cout <<f[n][1]<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}