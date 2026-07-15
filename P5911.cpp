#include <bits/stdc++.h>
#define int long long
#define inf 10000000
using namespace std;
int w,n,t[20];
int a[20];
int f[100005],m[100005],mw[100005];
// 1e3*64
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
    w=read(),n=read();
    for(int i=1;i<=n;i++){
        t[i]=read();
        a[i]=read();
    }
    for(int i=0;i<(1<<n);i++){
        f[i]=inf;
        for(int j=1;j<=n;j++){
            if((i&(1<<(j-1)))!=0){
                m[i]=max(m[i],t[j]);
                mw[i]=mw[i]+a[j];
            }
        }
    }
    f[0]=0;
    for(int i=0;i<(1<<n);i++){
        for(int j=i;j;j=i&(j-1)){
            if(mw[j]<=w) f[i]=min(f[i],f[i^j]+m[j]);
        }
    }
    cout <<f[(1<<n)-1]<<endl;
    return ;
}
signed main(){
    solve();
    return 0;
}