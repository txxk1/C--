#include <bits/stdc++.h>
using namespace std;
struct node{
    int to,nxt;
}e[400005];
struct out{
    int id,x;
}ans[600005];
int T,n,cnt,head[200005],dep[200005],anscnt,res[200005];
void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int x,int fa){
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y!=fa){
            res[x]++;
            dep[y]=dep[x]+1;
            dfs(y,x);
        }
    }
}
void solve(){
    cin >>n;
    cnt=0;
    anscnt=0;
    for(int i=1;i<=n;i++) head[i]=0,dep[i]=0,res[i]=0;
    for(int i=1;i<n;i++){
        int u,v;
        cin >>u>>v;
        add(v,u);
        add(u,v);
    }
    dfs(n,-1);
    vector<int> clac[2];
    for(int i=1;i<n;i++){
        if(res[i]==0){
            clac[dep[i]%2].push_back(i);
        }
    }
    int now=dep[1]%2;
    for(int i=1;i<n;i++){
        if(clac[now^1].size()==0){
            ans[++anscnt].id=1;
            now=now^1; 
        }
        ans[++anscnt].id=2;
        ans[anscnt].x=clac[now^1][clac[now^1].size()-1];
        clac[now^1].pop_back();
        int qwq=ans[anscnt].x;
        for(int i=head[qwq];i;i=e[i].nxt){
            res[e[i].to]--;
            if(res[e[i].to]==0){
                clac[dep[e[i].to]%2].push_back(e[i].to);
            }
        }
        ans[++anscnt].id=1;
        now=now^1;
    }
    cout <<anscnt<<endl;
    for(int i=1;i<=anscnt;i++){
        cout <<ans[i].id<<" ";
        if(ans[i].id==2) cout <<ans[i].x<<" ";
        cout <<endl;
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}