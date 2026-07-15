#include <bits/stdc++.h>
#define inf 1e18
#define int long long
using namespace std;
int T,n,m,k,dis[400005],head[400005],cnt,inq[400005];
inline int read(){
    int s=0,f=-1;
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
}e[800005];
void add(int u,int v,int w){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    e[cnt].w=w;
    head[u]=cnt;
}
void solve(){
    cin >>n>>m>>k;
    cnt=0;
    for(int i=1;i<=n+k;i++) dis[i]=inf,head[i]=0,inq[i]=0;
    for(int i=1;i<=m;i++){
        int x,y,z;
        x=read(),y=read(),z=read();
        add(x,y,z);
        add(y,x,z);
    }
    for(int i=1;i<=n;i++){
        int t;
        t=read();
        while(t--){
            int x,y;
            x=read(),y=read();
            add(i,n+x,y);
            add(n+x,i,0);
        }
    }
    dis[1]=0;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int qwq=Q.front();
        Q.pop();
        inq[qwq]=0;
        for(int i=head[qwq];i;i=e[i].nxt){
            int y=e[i].to;
            if(dis[y]>dis[qwq]+e[i].w){
                dis[y]=dis[qwq]+e[i].w;
                if(inq[y]==0){
                    Q.push(y);
                    inq[y]=1;
                }
            }
        }
    }
    cout <<dis[n]<<endl;
    return ;
}
signed main(){
    solve();
    return 0;
}