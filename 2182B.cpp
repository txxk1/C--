#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,a,b;
int f[100];
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
    cin >>a>>b;
    if(a<b) swap(a,b);
    int now=1,f=1,ans=0;
    // a>b
    // 
    int sa=a,sb=b,sum=0;
    while(1){
        if(f==1){
            if(sb>=now) ans++;
            else break;
            sb-=now;
        }
        if(f==-1){
            if(sa>=now) ans++;
            else break;
            sa-=now;
        }
        now=now*2;
        f=f*(-1);
    }
    now=1,f=1;
    sa=b,sb=a;
    while(1){
        if(f==1){
            if(sb>=now) sum++;
            else break;
            sb-=now;
        }
        if(f==-1){
            if(sa>=now)sum++;
            else break;
            sa-=now;
        }
        now=now*2;
        f=f*(-1);
    }
    cout <<max(ans,sum)<<endl;
}
signed main(){
    f[0]=1;
    for(int i=1;i<=10;i++) f[i]=f[i-1]*4;
    T=read();
    while(T--) solve();
    return 0;
}