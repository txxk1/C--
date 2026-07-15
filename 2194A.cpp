#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y;
int a[200005],s[200005];
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
    int sum=0,ans=0;
    n=read(),x=read(),y=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        s[i]=(a[i]/x)*(y);
        sum+=s[i];
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,a[i]+sum-s[i]);
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}