#include <bits/stdc++.h>
#define int long long
#define inf 1e9
using namespace std;
int T,n,ax,ay,bx,by;
int a[200005],f[200005][3],ma[200005],mi[200005];
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
struct node{
    int x,y;
}p[200005];
bool cmp(node a,node b){
    return a.x<b.x;
}
void solve(){
    n=read(),ax=read(),ay=read(),bx=read(),by=read();
    for(int i=1;i<=n;i++) p[i].x=read();
    for(int i=1;i<=n;i++) p[i].y=read();
    sort(p+1,p+1+n,cmp);
    int now=p[1].x,sum=1,minn=p[1].y,maxn=p[1].y;
    for(int i=2;i<=n;i++){
        if(p[i].x!=now){
            ma[sum]=maxn;
            mi[sum]=minn;
            now=p[i].x;
            minn=p[i].y;
            maxn=p[i].y;
            sum++;
        }
        else{
            maxn=max(maxn,p[i].y);
            minn=min(minn,p[i].y);
        }
    }
    ma[sum]=maxn;
    mi[sum]=minn;
    f[1][1]=abs(ay-mi[1])+ma[1]-mi[1];
    f[1][0]=abs(ay-ma[1])+ma[1]-mi[1];
    //for(int i=1;i<=n;i++) cout <<mi[i]<<" "<<ma[i]<<endl;
    for(int i=2;i<=sum;i++){
        
        f[i][0]=min(f[i-1][0]+abs(mi[i-1]-ma[i]),f[i-1][1]+abs(ma[i-1]-ma[i]))+ma[i]-mi[i];
        f[i][1]=min(f[i-1][0]+abs(mi[i-1]-mi[i]),f[i-1][1]+abs(ma[i-1]-mi[i]))+ma[i]-mi[i];
    }
    // 
    cout <<bx-ax+min(f[sum][0]+abs(by-mi[sum]),f[sum][1]+abs(by-ma[sum]))<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}
// f[1][0]=6
// f[2][0]=7
// 4+2+ 7