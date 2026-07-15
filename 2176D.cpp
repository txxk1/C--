#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,m,ans;
int u[200005],v[200005];
int a[200005],head[200005],cnt,vis[200005],f[70];
struct node{
    int to,nxt;
}e[200005];
void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int x,int fa,int dep){
    int flag=0;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y!=fa){
            if(vis[y]==1&&vis[x]==1) break;
            if(a[fa]+a[x]==a[y]){
                flag=1;
                vis[y]=1;
                dfs(y,x,dep+1);
            }
        }
    }
    if(flag==0) ans+=(dep+1)*dep/2;
}
// 
void solve(){
    ans=0;
    cnt=0;
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        head[i]=0;
        vis[i]=0;
    }
    for(int i=1;i<=m;i++){
        cin >>u[i]>>v[i];
        add(u[i],v[i]);
    }
    for(int i=1;i<=m;i++){
        if(vis[u[i]]==0||vis[v[i]]==0){
            vis[u[i]]=1;
            vis[v[i]]=1;
            dfs(v[i],u[i],1);
            cout <<"ok"<<endl;
            //dfs(v[i],u[i],0);
        }
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}