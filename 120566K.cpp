#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,z,k;
int a[100005];
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
    m=read(),n=read(),z=read();
    int x=z%(m+n);
    if(x==0) cout <<1;
    else if(x<=m) cout <<0;
    else cout <<1;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}