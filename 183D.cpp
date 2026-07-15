#include <bits/stdc++.h>
using namespace std;
int T,n,m,a[3003][303];
double f[3003][303];
void solve(){
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >>a[i][j];
        }
    }
    // f[i][j] 前i个人 i选j号的期望max
    // f[i][j]=max(f[i-1][k])+p/1000
    // 
    if(n==1){
        int mixn=-1;
        for(int i=1;i<=m;i++) mixn=max(mixn,a[1][i]);
        printf("%.9lf",(double)mixn/1000);
        return ;
    }
    for(int i=1;i<=m;i++){
        if(a[1][i]!=0) f[1][i]=1.00;
    }
    for(int i=2;i<=n;i++){
        double maxn=0.00;
        for(int j=1;j<=m;j++){
            if(maxn-f[i-1][j]<1e-8){
                maxn=f[i-1][j];
            }
        }
        for(int j=1;j<=m;j++){
            f[i][j]=maxn+(double)a[i][j]/1000;
        }
    }
    double ans=0.00;
    for(int i=1;i<=m;i++) {
        if(ans-f[n][i]<1e-8){
            ans=f[n][i];
        }
    }
    printf("%.9lf",ans);
}
int main(){
    solve();
    return 0;
}
// f[i][j]