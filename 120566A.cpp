#include <bits/stdc++.h>
#define eps 1e-8
#define int long long
using namespace std;
int T,n;
double x[500005],sx;
double y[500005],sy;
double w;
inline int read(){
    int s=0ll,f=1ll;
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
    double s,nxt,c;
    bool operator <(const node &a)const{
        return c-a.c<eps;
    }
};
void solve(){
    double ans=0.00;
    priority_queue<node>Q;
    cin >>n>>w;
    for(int i=1;i<=n;i++){
        cin >>x[i]>>y[i];
        sx+=x[i];
        sy+=y[i];
        Q.push((node){x[i]*x[i]+y[i]*y[i],y[i]*2.0-1.0,sqrt(x[i]*x[i]+y[i]*y[i])-sqrt(x[i]*x[i]+(y[i]-1.0)*(y[i]-1.0))});
    }
    int cnt=0;
    while(cnt!=w&&!Q.empty()){
        cnt++;
        node qwq=Q.top();
        Q.pop();
        if(qwq.nxt+1.0>eps) Q.push((node){qwq.s-qwq.nxt,qwq.nxt-2.0,sqrt(qwq.s-qwq.nxt)-sqrt(qwq.s-qwq.nxt-qwq.nxt+2.0)});
        else ans+=sqrt(qwq.s);
    }
    while(!Q.empty()){
        node qwq=Q.top();
        Q.pop();
        ans+=sqrt(qwq.s);
    }
    printf("%.8lf",ans);
    return ;
}
signed main(){
    solve();
    return 0;
}