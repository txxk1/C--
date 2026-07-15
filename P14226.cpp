#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,k,cnt,head[500005];
struct node{
    int to,nxt,id,w;
}e[1000005];
void add(int u,int v,int id,int w){
    e[++cnt].to=v;
    e[cnt].id=id;
    e[cnt].w=w;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void solve(){
    cin >>n>>m>>k;
    cnt=0;
    for(int i=1;i<=n;i++) head[i]=0;
    for(int i=1;i<=m;i++){
        int u,v,id,w;
        cin >>u>>v>>id>>w;
        add(u,v,id,w);
        add(v,u,id,w);
    }
    for(int i=1;i<=k;i++){
        int a,b;
        cin >>a>>b;
        
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}