#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,cnt;
int a[200005],dis[200005],head[200005],inq[200005];
struct node{
    int to,nxt,w;
}e[400005];
void add(int u,int v,int w){
    e[++cnt].to=v;
    e[cnt].w=w;
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

void solve(){
    int ans=0,now=0;
    n=read();
    for(int i=2;i<=n;i++){
        int u=read(),v=read(),w=read();
        add(u,v,w);
        add(v,u,w);
        dis[i]=2e9;
        a[i]=2e9;
    }
    a[1]=1;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        inq[now]=0;
        for(int i=head[now];i;i=e[i].nxt){
            if(a[e[i].to]==2e9) a[e[i].to]=e[i].w-a[now];
            else if(a[e[i].to]!=e[i].w-a[now]){
                cout <<"NO"<<endl;
                return ;
            }
            if(dis[e[i].to]>dis[now]+1){
                dis[e[i].to]=dis[now]+1;
                if(inq[e[i].to]==0){
                    inq[e[i].to]=1;
                    Q.push(e[i].to);
                }
            }
        }
    }
    int min0=2e9,min1=2e9;
    for(int i=1;i<=n;i++){
        //cout <<i<<" "<<dis[i]<<" "<<a[i]<<endl;
        if(dis[i]%2==0) min0=min(min0,a[i]);
        if(dis[i]%2==1) min1=min(min1,a[i]);
    }
    if(min0+min1<2){
        cout <<"NO"<<endl;
        return ;
    }
    cout <<"YES"<<endl;
    if(min0<1){
        int add=1-min0;
        for(int i=1;i<=n;i++){
            if(dis[i]%2==0) a[i]+=add;
            else a[i]-=add;
        }
    }
    for(int i=1;i<=n;i++){
        cout <<a[i]<<" ";
    }
    cout <<endl;
}
signed main(){
    solve();
    return 0;
}
/*
5
1 2 5
1 3 4
2 5 7
3 4 2
*/