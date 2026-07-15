#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
int a[200005],b[200005],inj[200005];
const int mod=998244353;
inline int read(){
    int s=0ll,f=1ll;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1ll;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return s*f;
}
int qpow(int x,int y){
    int ss=1ll,now=x;
    while(y){
        if(y%2) ss=ss*now%mod;
        now=now*now%mod;
        y=y/2;
    }
    return ss;
}

void solve(){
    int ans=0ll,flag;
    n=read();
    map<int,int> Q;
    for(int i=1;i<=n;i++) a[i]=read(),Q[a[i]]=1;
    for(int i=1;i<=n;i++) b[i]=read();
    /*
    for(int i=1;i<=n;i++){
        if(a[i]==1) flag=1;
        if(b[i]==1) flag=0;
    }
    if(!flag){
        cout <<inj[n]<<endl;
        return ;
    }
    */
    int now=1;
    while(1){
        if(Q[now]==1) now++;
        else break;
    }
    cout <<inj[now-1]*inj[n-now+1]%mod<<endl;
    return ;
}
signed main(){
    inj[0]=1ll;
    inj[1]=1ll;
    for(int i=2;i<=200000;i++) inj[i]=inj[i-1]*i%mod;
    T=read();
    while(T--) solve();
    return 0;
}
// 3!*