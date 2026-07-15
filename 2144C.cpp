#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int T,n,a[105],b[105],f[105][2];
// f[i][0] 第i个数不选择 swap 的ans
// f[i][1] 第i个数选择 swap 的ans
void solve(){
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i],f[i][0]=0;
    for(int i=1;i<=n;i++) cin >>b[i],f[i][1]=0;
    f[1][0]=1;
    f[1][1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]>=a[i-1]&&b[i]>=b[i-1]){
            f[i][0]=(f[i][0]+f[i-1][0])%mod;
            f[i][1]=(f[i][1]+f[i-1][1])%mod;
        } 
        if(a[i]>=b[i-1]&&b[i]>=a[i-1]){
            f[i][0]=(f[i][0]+f[i-1][1])%mod;
            f[i][1]=(f[i][1]+f[i-1][0])%mod;
        }
    }
    cout <<(f[n][0]+f[n][1])%mod<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}