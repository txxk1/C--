#include <bits/stdc++.h>
#define inf 1e16
#define int long long
using namespace std;
int T,n,a[200005],f[200005];
int cost(int x,int y,int z){
    return max(x,max(y,z))-min(x,min(y,z));
}
void solve(){
    int ans=inf;
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int k=1;k<=4;k++){
        f[0]=0;
        //f[1]=inf;
        for(int i=1;i<=n;i++) f[i]=inf;
        for(int i=2;i<=n;i++){
            f[i]=min(f[i],f[i-2]+abs(a[i]-a[i-1]));
            if(i==2) continue;
            f[i]=min(f[i],f[i-3]+cost(a[i],a[i-1],a[i-2]));
        }
        ans=min(ans,f[n]);
        for(int i=2;i<=n;i++) swap(a[i],a[i-1]);
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}