#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[100005],c[105],t[105],cnt;
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
    int cnt=1;
    n=read();
    a[n]=1;
    for(int i=n-1;i>=1;i--){
        if((n-i)%2==1) a[i]=n-cnt+1;
        else a[i]=++cnt;
    }
    for(int i=1;i<=n;i++) cout <<a[i]<<" ";
    cout <<endl;
    return ;
}
//n-1 2 n 1
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}
// 