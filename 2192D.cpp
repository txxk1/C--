#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,head[200005],cnt,a[200005],s[200005],dep[200005],f[200005];
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
int S;
struct node{
    int to,nxt;
}e[400005];
void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int x,int fa){
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y!=fa){
            dep[y]=dep[x]+1;
            dfs(y,x);
            s[x]+=s[y];
        }
    }
}
void dfs2(int x,int fa){
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y!=fa){
            //f[y]=f[x]-s[x]+S-s[x];
            dfs2(y,x);
        }
    }
}
void solve(){
    int ans=0,sum=1e9,maxn=-1;
    S=0;
    cnt=0;
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),head[i]=0,dep[i]=0,s[i]=a[i],f[i]=0;
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        add(u,v);
        //add(v,u);
    }
    dep[1]=0;
    dfs(1,-1);
    for(int i=1;i<=n;i++) maxn=max(maxn,dep[i]),S+=a[i];
    for(int i=2;i<=n;i++){
        ans+=dep[i]*a[i];
        //sum=min(sum,(maxn-dep[i])*s[i]);
    }
    f[1]=ans;
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
        cout <<f[i]<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}