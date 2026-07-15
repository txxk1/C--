#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
const int mod=1e9+7;
struct node{
    int cnt,w;
    bool operator < (const node &a)const{
        return a.w<w;
    }
}e[100005];
bool cmp(node a,node b){
    return a.w<b.w;
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
    int ans=0ll,cnt=0,sum=0ll;
    cin >>n;
    priority_queue<node>Q;
    for(int i=1;i<=n;i++){
        cin >>e[i].cnt>>e[i].w;
        sum+=e[i].cnt;
        Q.push(e[i]);
    }
    while(cnt<sum-1){
        node qwq=Q.top();
        Q.pop();
        int s=qwq.cnt;
        if(s>=2) Q.push((node){s/2,qwq.w*2});
        ans=(ans+(s/2)*qwq.w*2)%mod;
        cnt+=s/2;
        if(s%2==1){
            //Q.top().cnt--;
            node qaq=Q.top();
            Q.pop();
            if(qaq.cnt>1) Q.push((node){qaq.cnt-1,qaq.w});
            Q.push((node){1,qwq.w+qaq.w});
            ans+=qwq.w+qaq.w;
            cnt++;
        }
        //cout <<ans<<" "<<cnt<<endl;
    }
    cout <<ans%mod<<endl;
    return ;
}
// 1*3+3*2+4
// 2 3 4
// 
signed main(){
    solve();
    return 0;
}