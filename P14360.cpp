#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int n,a[5005],f[5005],ans,jie[5005],s[5005];
void solve(){
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i];
    sort(a+1,a+1+n);

    // f[i][x] 前i个数排列总和>=x的个数
    // f[i][x]=f[i-1][x]+f[i-1][x-a[i]] x>=a[i]
    // x<a[i] f[i][x]=f[i-1][x]+(i-1)! 
    for(int i=0;i<=a[1];i++) f[i]=1;
    //f[1][a[1]]=1;
    for(int i=2;i<=n;i++){
        //cout <<f[i-1][a[i]+1]<<endl;
        
        ans=(ans+s[a[i]+1])%mod;
        for(int j=0;j<=5001;j++){
            if(j<=a[i]) s[j]=(f[j]+jie[i-1])%mod;
            else s[j]=(f[j]+f[j-a[i]])%mod;
        }
        for(int j=0;j<=5001;j++) f[j]=s[j];
    }
    cout <<ans;
    return ;
}
/*
f[3][5]=f[2][5]+f[2][2]
f[2][5]=0;
f[2][2]=f[]
*/
signed main(){
    //freopen("polygon4.in","r",stdin);
    jie[0]=1;
    jie[1]=2;
    for(int i=2;i<=5000;i++) jie[i]=(jie[i-1]*2)%mod;
    solve();
    return 0;
}