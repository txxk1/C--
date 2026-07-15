#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[1200005],td,b[1200005],t[1200005],ta[1000005];
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
int ans[1000005],cnt;
void solve(){
    int flag=0;
    cnt=0;
    n=read();
    for(int i=1;i<=n;i++) t[i]=0,ta[i]=0;
    for(int i=1;i<=n;i++) a[i]=read(),t[a[i]]++,ta[a[i]]++;
    for(int i=1;i<=n;i++) b[i]=read(),t[b[i]]++;
    for(int i=1;i<=n;i++){
        if(t[i]%2==1) flag=1;
    }
    if(flag==1){
        cout <<-1<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(ta[i]==0) 0;
    }
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}