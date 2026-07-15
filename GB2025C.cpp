#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[200005],f[200005];
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
    int ans=-2e9,minn=2e9,cnt=0,sum=0;
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    f[n+1]=0;
    for(int i=n;i>=1;i--){
        f[i]=f[i+1]-a[i];
    }
    int now=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,now+f[i+1]);
        if(i!=1) now+=abs(a[i]);
        if(i==1) now+=a[i];
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}
// 