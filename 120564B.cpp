#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,s,q,pre[200005];
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
    int maxn=-1,maxnx,maxny;
    n=read(),q=read(),s=read();
    for(int i=1;i<=n;i++) pre[i]=read(),pre[i]+=pre[i-1];
    while(q--){
        int x=read(),y=read();
        cout <<s+pre[x-1]+y-1<<endl;
    }
    return ;
}
signed main(){
    solve();
    return 0;
}