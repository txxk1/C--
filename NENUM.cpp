#include <bits/stdc++.h>
#define int long long
#define inf 1000000007
using namespace std;
int T,n,m;
int a[105][105],f[105][105];
void solve(){
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >>a[i][j];
        }
    }
    f[n][1]=a[n][1];
    for(int i=n-1;i>=1;i--){
        f[i][1]=f[i+1][1]+a[i][1];
    }
    for(int i=1;i<=m;i++){
        f[n][i]=f[n][i-1]+a[n][i];
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=m;j++){
            f[i][j]=max(f[i+1][j]+a[i][j],f[i][j-1]+a[i][j]);
        }
    }
    cout <<f[1][m]<<endl;
}
signed main(){
    solve();
    return 0;
}