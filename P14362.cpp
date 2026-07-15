#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,k,ans,x,fa[10015],vis[11],inq[10005],t[22];
vector<int> f[11];
int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
struct node{
    int u,v,w;
}e[1100005];
bool cmp(node a,node b){
    return a.w<b.w;
}
void solve(){
    cin >>n>>m>>k;
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        cin >>e[i].u>>e[i].v>>e[i].w;
    }
    int cnt=m;
    for(int i=1;i<=k;i++){
        cin >>x;
        t[i]=x;
        for(int j=1;j<=n;j++){
            cin >>x;
            e[++cnt].u=j;
            e[cnt].v=n+i;
            e[cnt].w=x;
            e[++cnt].u=n+i;
            e[cnt].v=j;
            e[cnt].w=x;
        }
    }
    int qwq=0;
    sort(e+1,e+1+cnt,cmp);
    for(int i=1;i<=cnt;i++){
        if(qwq>=n) break;
        if(e[i].u>n){
            if(inq[e[i].v]==1) continue;
            f[e[i].u-n].push_back(e[i].v);
            if(vis[e[i].u-n]==1){
                inq[e[i].v]=1;
                qwq++;
            }
            ans+=e[i].v;
        }
        else if(e[i].v>n){
            ans+=e[i].w;
            vis[e[i].u]=1;
            for(int j=0;j<f[e[i].u].size();j++){
                if(inq[f[e[i].u][j]]==0){
                    inq[f[e[i].u][j]]=1;
                    qwq++;
                }
            }
        }
        else{
            if(find(e[i].u)!=find(e[i].v)){
                fa[find(e[i].u)]=find(e[i].v);
                ans+=e[i].w;
                inq[e[i].u]=1;
                inq[e[i].v]=1;
                qwq++;
            }
        }
    }
    cout <<ans<<endl;
    return ;
}

signed main(){
    solve();
    return 0;
}