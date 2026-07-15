#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[300005],c[300005],ans[300005];
inline int read(){
    int s=0ll,f=1ll;
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
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=2;i<n;i++){
        ans[i]=(a[i-1]+a[i+1]-a[i]-a[i])/2;
    }
    ans[n]=a[1];
    for(int i=2;i<n;i++){
        ans[n]-=ans[i]*(i-1);
    }
    ans[n]=ans[n]/(n-1);
    ans[1]=a[n];
    for(int i=2;i<n;i++){
        ans[1]-=ans[i]*(n-i);
    }
    ans[1]=ans[1]/(n-1);
    for(int i=1;i<=n;i++) cout <<ans[i]<<" ";
    cout <<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}