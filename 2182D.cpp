#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[55];
int p[1000005];
const int mod=998244353;
inline int read(){
    int s=0,f=1ll;
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
int qpow(int x,int y){
    int now=x,s=1ll;
    while(y){
        if(y%2) s=s*now%mod;
        now=now*now%mod;
        y=y/2;
    }
    return s;
}
int C(int x,int y){
    return p[x]*qpow(p[y],mod-2)%mod*qpow(p[x-y],mod-2)%mod;
}
void solve(){
    int sum=0ll,ans=1ll,flag=0;
    n=read();
    for(int i=0;i<=n;i++) a[i]=read(),sum+=a[i];
    int k=sum/n,res=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=k){
            res++;
            a[0]-=k-a[i];
        }
        else if(a[i]>k+1) flag=1;
    }
    if(a[0]<0||a[0]>res){
        flag=1;
    }
    if(flag){
        cout <<0<<endl;
        return ;        
    }
    ans=ans*p[res]%mod;
    ans=ans*p[n-res+a[0]]%mod;
    ans=ans*qpow(p[a[0]],mod-2)%mod;
    cout <<ans<<endl;
    return ;
}
signed main(){
    p[0]=1ll;
    for(int i=1ll;i<=1e6;i++) p[i]=p[i-1]*i%mod;
    T=read();
    while(T--) solve();
    return 0;
}