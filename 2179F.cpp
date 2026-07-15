#include <bits/stdc++.h>
#define inf 1e9+7
#define int long long
using namespace std;
int T,n,k,dis[200005],head[200005],cnt,m,inq[200005];
char a[200005];
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
    int to,nxt;
}e[400005];
void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
const char col[5]={'r','b','g'};
void solve1(){
    cin >>n>>m;
    cnt=0;
    for(int i=1;i<=n;i++) dis[i]=inf,head[i]=0,inq[i]=0;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >>x>>y;
        add(x,y);
        add(y,x);
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
            if(dis[y]>dis[qwq]+1){
                dis[y]=dis[qwq]+1;
                if(inq[y]==0){
                    Q.push(y);
                    inq[y]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout <<col[dis[i]%3];
    }
    cout <<endl;
    return ;
}
void solve2(){
    cin >>n;
    cin >>a+1;
    int ar=0,ab=0,ag=0;
    for(int i=1;i<=n;i++){
        if(a[i]=='r') ar=1;
        if(a[i]=='b') ab=1;
        if(a[i]=='g') ag=1;
    }
    char now;
    if(ar+ab+ag==1){
        cout <<1<<endl;
        return ;
    }
    if(ar+ab==2) now='b';
    if(ab+ag==2) now='g';
    if(ar+ag==2) now='r';
    for(int i=1;i<=n;i++){
        if(a[i]==now){
            cout <<i<<endl;
            return ;
        }
    }
}
signed main(){
    string op;
    cin >>op;
    cin >>T;
    if(op=="first"){
        while(T--) solve1();
    }
    else{
        while(T--){
            int q;
            cin >>q;
            while(q--) solve2();
        }
    }
    return 0;
}