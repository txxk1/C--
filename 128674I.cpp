#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,head[300005];
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
struct node{
    int to,nxt,w;
}e[400005];
void solve(){
    n=read(),k=read();
    for(int i=1;i<=n;i++) {
        int x=read();
        
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
}