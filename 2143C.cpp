#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
    return k*f;
}
int T,u,v,x,y,n,to[200005],out[200005],a[200005],head[200005],cnt;
struct node{
    int to,nxt;
}e[200005];
void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void solve(){/*
    memset(head,0,sizeof(head));
    memset(to,0,sizeof(to));
    memset(out,0,sizeof(out));
    memset(a,0,sizeof(a));*/
    cnt=0;
    n=read();
    for(int i=1;i<=n;i++){
        head[i]=to[i]=out[i]=a[i]=0;
    }
    for(int i=1;i<n;i++){
        u=read(),v=read(),x=read(),y=read();
        if(u>v) swap(u,v);
        if(y>x){
            to[v]++;
            out[u]++;
            add(u,v);
        }
        else {
            to[u]++;
            out[v]++;
            add(v,u);
        }
        
    }
    queue<int> Q;
    int now=0;
    for(int i=1;i<=n;i++){
        if(to[i]==0) Q.push(i);
    }
    while(!Q.empty()){
        int qwq=Q.front();
        Q.pop();
        if(a[qwq]==0) a[qwq]=++now;
        for(int i=head[qwq];i;i=e[i].nxt){
            int qvq=e[i].to;
            to[qvq]--;
            if(to[qvq]==0&&a[qvq]==0) Q.push(qvq);
        }
    }
    for(int i=1;i<=n;i++) cout <<a[i]<<" ";
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
/*

2<3
2<4
1>5
1<2
5 1 2 3 4 
*/