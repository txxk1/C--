#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,q;
int a[200005],b[200005],s[200005];
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
    n=read(),q=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    a[n+1]=0;
    
    for(int i=1;i<=n;i++){
        b[i]=read();
    }
    for(int i=n;i>=1;i--){
        a[i]=max(a[i],b[i]);
        a[i]=max(a[i],a[i+1]);
    }
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=q;i++){
        int l=read(),r=read();
        cout <<s[r]-s[l-1]<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}
// an^(n-1)==an-1