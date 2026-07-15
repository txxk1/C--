#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
int x,y,q;
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
    int t,e;
}a[100005];
bool cmp(node x,node y){
    return x.t<y.t;
}
void solve(){
    int now=0;
    n=read();
    for(int i=1;i<=n;i++) {
        a[i].t=read();
        a[i].e=read();
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        now=max(now,a[i].t);
        now+=a[i].e;
    }
    cout <<now<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}