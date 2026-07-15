#include <bits/stdc++.h>

using namespace std;
int n,m,dis[10005][4],cnt,head[10005],inq[10005];
struct node{
    int to,nxt,w,d;
}e[200005];
void add(int u,int v,int w,int d){
    e[++cnt].to=v;
    e[cnt].w=w;
    e[cnt].d=d;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void spfa(){
    memset(dis,0x3f,sizeof(dis));
    queue<int> Q;
    Q.push(1);
    inq[1]=1;
    dis[1][0]=0;
    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        inq[now]=0;
        for(int i=head[now];i;i=e[i].nxt){
            for(int k=0;k<=2;k++){
                //dis[e[i].to][k]=min(dis[now][k]+e[i].w,dis[e[i].to][k]); 
                if(e[i].d==1){
                    if(dis[e[i].to][k+1]>dis[now][k]+e[i].w){
                        dis[e[i].to][k+1]=dis[now][k]+e[i].w;
                        if(inq[e[i].to]==0){
                            Q.push(e[i].to);
                            inq[e[i].to]=1;
                        }                 
                    }
                }
                else{
                    if(dis[e[i].to][k]>dis[now][k]+e[i].w){
                        dis[e[i].to][k]=dis[now][k]+e[i].w;
                        if(inq[e[i].to]==0){
                            Q.push(e[i].to);
                            inq[e[i].to]=1;
                        }
                    }
                }
            }
        }
    }
    return ;
}
int main(){
    cin >>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c,d;
        cin >>a>>b>>c>>d;
        add(a,b,c,d);
        add(b,a,c,d);
    }
    spfa();
    //int ans=1e9;
    //for(int i=0;i<=2;i++) ans=min(ans,dis[n][i]);
    cout <<dis[n][0]-min(dis[n][2],dis[n][1]);
    return 0;
}