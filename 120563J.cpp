#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
int p[103],nxt[103];
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
void debug(){
    cout <<"BUg"<<endl;
}
void solve(){
    int dep,sum=0ll;
    n=read(),m=read();
    for(int i=1;i<=60;i++){
        sum+=p[i];
        if(sum>=n){
            dep=i;
            break;
        }
    }
    for(int i=1;i<dep;i++) nxt[i]=p[i],n-=nxt[i];
    nxt[dep]=n;
    for(int i=1;i<=m;i++){
        int x=read(),qwq=0;
        //debug();
        for(int j=0;j<dep;j++){
            if((1ll<<j)<=x) qwq=j+1;
        }
        cout <<nxt[qwq]<<endl;
    }
    return ;
}

signed main(){
    p[1]=1ll;
    for(int i=2;i<=60;i++) p[i]=p[i-1]*2ll;
    T=read();
    while(T--) solve();
    return 0;
}