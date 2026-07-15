#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,Q,a[500005];
int x,y,q;
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
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
int lcm(int x,int y){
    if(x==0) return y;
    if(y==0) return x;
    return x/gcd(x,y)*y;
}
void solve(){
    int ans=0;
    n=read(),m=read(),Q=read();
    for(int i=1;i<=n;i++) a[i]=0;
    for(int i=1;i<=m;i++){
        x=read(),y=read(),q=read();
        a[x]=lcm(a[x],q);
        a[y]=lcm(a[y],q);
    }
    for(int i=1;i<=Q;i++){
        x=read(),y=read();
        if(a[x]==0) printf("%lld\n",a[y]);
        else if(a[y]==0) printf("%lld\n",a[x]);
        else printf("%lld\n",gcd(a[x],a[y]));
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}