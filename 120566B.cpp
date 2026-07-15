#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,x,t;
int j[1000005],p[1000005],invj[1000005];
inline int read(){
    int s=0ll,f=1ll;
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
    int s=1,now=x;
    while(y){
        if(y%2) s=s*now%mod;
        now=now*now%mod;
        y=y/2;
    }
    return s;
}
int C(int x,int y){
    if(y>x) return 0;
    if(y<0) return 0;
    return j[x]*invj[y]%mod*invj[x-y]%mod;
}
void solve(){
    int ans=0;
    n=read(),x=read(),t=read();
    int qwq=(t+1)/2;
    if(t==0){
        if(x==0||x==n) cout <<1<<endl;
        else cout <<0<<endl;
        return ;
    }
    cout <<(C(x-1,t-qwq)*C(n-x-1,qwq-1)%mod+C(n-x-1,t-qwq)*C(x-1,qwq-1)%mod)%mod<<endl;
    return ;
}
// x1+x2+x3+.. +xt==n
// 
// 1 2
// x x-1
// x
signed main(){
    j[0]=1;
    p[0]=1;
    invj[0]=1;
    for(int i=1;i<=1000000;i++) j[i]=j[i-1]*i%mod;
    for(int i=1;i<=1000000;i++) p[i]=p[i-1]*2%mod;
    for(int i=1;i<=1000000;i++) invj[i]=invj[i-1]*qpow(i,mod-2)%mod;
    cin >>T;
    while(T--) solve();
    return 0;
}