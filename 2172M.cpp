#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,x,cnt,head[200005],dis[200005];
struct node{
    int to,nxt;
}e[400005];
vector<int> Q[200005];
void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int x){
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int qwq=q.front();
        q.pop();
        for(int i=head[qwq];i;i=e[i].nxt){
            int y=e[i].to;
            if(dis[y]>dis[qwq]+1){
                dis[y]=dis[qwq]+1;
                q.push(y);
            }
        }
    }
}
void solve(){
    cin >>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin >>x;
        Q[x].push_back(i);
        dis[i]=1e9;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin >>u>>v;
        add(u,v);
        add(v,u);
    }
    
    dis[1]=0;
    dfs(1);
    
    for(int i=1;i<=k;i++){
        int ans=0;
        for(int j=0;j<Q[i].size();j++){
            ans=max(ans,dis[Q[i][j]]);
        }
        cout <<ans<<" ";
    }
    return ;
}
signed main(){
    solve();
    return 0;
}