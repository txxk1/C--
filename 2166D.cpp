#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,a[5005],f[5005][5005],C[5005][5005];
void init(){
    C[1][0]=1;
    C[1][1]=1;
    for(int i=2;i<=5000;i++){
        C[i][0]=1;
        C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
}
void solve(){
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i];
    //cout <<sum<<endl;
    return ;
}
signed main(){
    init();
    cin >>T;
    while(T--) solve();
    return 0;
}