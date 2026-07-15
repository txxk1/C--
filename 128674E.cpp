#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,k,a[200005],f[200005][205],s[200005][205],S[200005][205];
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return s*f;
}
void solve(){
    int ans=0;
    n=read(),k=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            f[i][j]=0;
            s[i][j]=0;
            S[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++) f[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            //if(a[i]!=a[i-1]) f[i][j]=(f[i][j]+f[i-1][j])%mod;
            //else f[i][j+1]=(f[i][j+1]+f[i-1][j])%mod;
            if(j==0) f[i][j]=(f[i][j]+S[i-1][j]-s[a[i]][j]+mod)%mod;
            else{
                f[i][j]=(f[i][j]+S[i-1][j]-s[a[i]][j]+s[a[i]][j-1]+mod)%mod;
            }
        }
        for(int j=0;j<=k;j++){
            s[a[i]][j]=(s[a[i]][j]+f[i][j])%mod;
        }
        for(int j=0;j<=k;j++){
            S[i][j]=(S[i-1][j]+f[i][j])%mod;
        }
    }
    // 1 2 3
    // 2 3
    // 1 4
    // 1 2 3 4
    // 2 3 4
    // f[i][j]= \sigema f[k][j] a[i]!=a[k]
    //                  f[k][j-1] a[i]==a[k]
    // f[3][1]=S[2][1]-s[2][1]+s[2][0]
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            //cout <<i<<" "<<j<<" "<<f[i][j]<<endl;
        }
        ans=(ans+f[i][k])%mod;
    }
    if(k!=0) cout <<ans<<endl;
    else cout <<(ans+1)%mod<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
}
// fi,j=\sigema fk,j-1 a[k]==a[i]