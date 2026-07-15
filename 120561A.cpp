#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,c;
int p[10],num[10],s[3000];
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
int s0[10]={1,1,1,0,1,1,1};
int s1[10]={0,0,1,0,0,1,0};
int s2[10]={1,0,1,1,1,0,1};
int s3[10]={1,0,1,1,0,1,1};
int s4[10]={0,1,1,1,0,1,0};
int s5[10]={1,1,0,1,0,1,1};
int s6[10]={1,1,0,1,1,1,1};
int s7[10]={1,0,1,0,0,1,0};
int s8[10]={1,1,1,1,1,1,1};
int s9[10]={1,1,1,1,0,1,1};
int ask(int x){
    if(x==-1) return 0;
    int now=1ll;
    for(int k=0;k<7;k++) now=now*qpow(100ll,mod-2)%mod;
    if(x==0){
        for(int k=0;k<7;k++){
            if(s0[k]==1) now=now*p[k]%mod;
            else now=now*(100-p[k])%mod;
        }
    }
    if(x==1){
        for(int k=0;k<7;k++){
            if(s1[k]==1) now=now*p[k]%mod;
            else now=now*(100-p[k])%mod;
        }
    }
    if(x==2){
        for(int k=0;k<7;k++){
            if(s2[k]==1) now=now*p[k]%mod;
            else now=now*(100-p[k])%mod;
        }
    }
    if(x==3){
        for(int k=0;k<7;k++){
            if(s3[k]==1) now=now*p[k]%mod;
            else now=now*(100-p[k])%mod;
        }
    }
    if(x==4){
        for(int k=0;k<7;k++){
            if(s4[k]==1) now=now*p[k]%mod;
            else now=now*(100-p[k])%mod;
        }
    }
    if(x==5){
        for(int k=0;k<7;k++){
            if(s5[k]==1) now=now*p[k]%mod;
            else now=now*(100-p[k])%mod;
        }
    }
    if(x==6){
        for(int k=0;k<7;k++){
            if(s6[k]==1) now=now*p[k]%mod;
            else now=now*(100-p[k])%mod;
        }
    }
    if(x==7){
        for(int k=0;k<7;k++){
            if(s7[k]==1) now=now*p[k]%mod;
            else now=now*(100-p[k])%mod;
        }
    }
    if(x==8){
        for(int k=0;k<7;k++){
            if(s8[k]==1) now=now*p[k]%mod;
            else now=now*(100-p[k])%mod;
        }
    }
    if(x==9){
        for(int k=0;k<7;k++){
            if(s9[k]==1) now=now*p[k]%mod;
            else now=now*(100-p[k])%mod;
        }
    }
    return now;
}
int query(int x,int y){
    int s=1ll;
    for(int k=1;k<=4;k++){
        int qwq=x%10;
        s=s*ask(qwq)%mod;
        x=x/10;
        qwq=y%10;
        s=s*ask(qwq)%mod;
        y=y/10;
    }
    return s;
}
void pre(){
    for(int i=0;i<=9;i++){
        num[i]=ask(i);
    }
    for(int i=0;i<=c;i++){
        int now=i,sss=1ll;
        for(int j=1;j<=4;j++){
            sss=sss*num[now%10]%mod;
            now=now/10;
        }
        s[i]=sss;
    }
}
void solve(){
    int ans=0ll,cnm=1ll;
    c=read();
    for(int i=0;i<7;i++) p[i]=read();
    pre();
    for(int i=0ll;i<=c;i++){
        ans=(ans+s[i]*s[c-i]%mod)%mod;
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}