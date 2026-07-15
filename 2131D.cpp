#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,u,v,sum,cnt,head[200005],ans,dep[200005],deg[200005];
struct node{
    int to,nxt;
}e[400005];
void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void find(int x,int fa){
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y!=fa){
            dep[y]=dep[x]+1;
            find(y,x);
        }
    }
}
void dfs(int x,int dep,int fa){
    int flag=0;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y!=fa){
            dfs(y,dep+1,x);
            flag=1;
        }
    }
    if(flag==0&&dep>2) ans++;
    return ;
}
void solve(){
    ans=0;
    sum=0;
    cnt=0;
    cin >>n;
    
    for(int i=1;i<=n;i++) head[i]=0,dep[i]=0,deg[i]=0;
    for(int i=1;i<n;i++){
        cin >>u>>v;
        add(u,v);
        add(v,u);
        deg[u]++;
        deg[v]++;
    }
    if(n<=2){
        cout <<0<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(deg[i]==1) ans++;
    }
    for(int i=1;i<=n;i++){
        int qwq=0;
        for(int j=head[i];j;j=e[j].nxt){
            int k=e[j].to;
            if(deg[k]==1) qwq++;
        }
        sum=max(sum,qwq);
    }
    cout <<ans-sum<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}