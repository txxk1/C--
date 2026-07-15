#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,q;
int a[300005],pre[300005];
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
    n=read(),q=read();
    for(int i=1;i<=(1<<n);i++){
        a[i]=read();
        pre[i]=pre[i-1]^a[i];
    }
    while(q--){
        int pos=read(),x=read(),ans=0;
        for(int i=0;i<n;i++){
            int len=(1<<i);
            int l=(pos-1)/len;
            int nowx=pre[l*len]^pre[l*len+len],nxtx;
            nowx^=a[pos];
            nowx^=x;
            if(l%2==1){
                nxtx=pre[l*len]^pre[l*len-len];
                if(nowx<=nxtx) ans+=len;
            }
            else{
                nxtx=pre[l*len+len]^pre[l*len+len+len];
                if(nowx<nxtx) ans+=len;
            }
        }
        cout <<ans<<"\n";
    }
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}