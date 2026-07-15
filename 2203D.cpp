#include <bits/stdc++.h>
#define int long long
#define inf 1e9
using namespace std;
int T,n,m;
int a[1000005],b[1000005],t[2000005],tb[2000005];
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
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
int lcm(int x,int y){
    if(x==0) return y;
    if(y==0) return x;
    return x*y/gcd(x,y); 
}
void solve(){
    int suma=0,sumb=0,now=0,pub=0;
    n=read(),m=read();
    for(int i=1;i<=n+m;i++) t[i]=0,tb[i]=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(now!=inf)now=lcm(now,a[i]);
        if(now>n+m) now=inf;
        t[a[i]]=1;
    }    
    for(int i=1;i<=n+m;i++){
        if(t[i]==0) continue;
        for(int j=1;j*i<=n+m;j++){
            tb[i*j]=1;
        }
    }
    for(int i=1;i<=m;i++){
        b[i]=read();
        if(tb[b[i]]==1&&b[i]%now==0) suma++;
        else if(tb[b[i]]==1&&b[i]%now!=0) pub++;
        else sumb++;
    }
    if(pub%2==1) suma++;
    if(suma>sumb) cout <<"Alice"<<endl;
    else cout <<"Bob"<<endl;
    return ;
}
// 6 8 14
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}