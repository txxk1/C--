#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,pos[200005];
char a[200005];
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
    int x,id;
}e[200005],ad[200005];
bool cmp(node a,node b){
    return a.x<b.x;
}
void solve(){
    int cnt=0,ans=2e9;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>e[i].x;
        e[i].id=i;
    }
    sort(e+1,e+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(e[i].id!=i){
            if(e[i].x==e[e[i].id].x) continue;
            ad[++cnt].x=e[i].x;
            ad[cnt].id=e[i].id;
            ans=min(ans,max(e[i].x-e[1].x,e[n].x-e[i].x));
        }
    }
    if(cnt==0){
        cout <<-1<<endl;
        return ;
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}