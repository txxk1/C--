#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int head[200005],cnt,dfn[200005],vis[200005],dfncnt;
struct node{
    int to,nxt;
}e[400005];
void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
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
void dfs(int now,int fa){
    if(vis[now]==0){
        dfn[++dfncnt]=now;
        vis[now]=1;
    }
    for(int i=head[now];i;i=e[i].nxt){
        int y=e[i].to;
        if(y!=fa){
            dfs(y,now);
        }
    }
}
int query(int a,int b){
    int num;
    cout <<"? "<<a<<" "<<b<<endl;
    return num=read();
}
void print(int ans){
    cout <<"! "<<ans<<endl;
}
void solve(){
    n=read();
    cnt=0;
    dfncnt=0;
    for(int i=1;i<=n;i++) head[i]=0,vis[i]=0,dfn[i]=0;
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        add(u,v);
        add(v,u);
    }
    dfs(1,-1);
    for(int i=1;i<n;i+=2){
        if(query(dfn[i],dfn[i+1])==1){
            if(query(dfn[i],dfn[i])==1) print(dfn[i]);
            else print(dfn[i+1]);
            return ;
        }
    }
    print(dfn[n]);
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}