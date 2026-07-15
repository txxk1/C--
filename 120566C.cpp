#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n;
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
    int l,r,s;
}t[4000005];
map<pair<int,int> ,int> Q;
void build(int id,int l,int r){
    if(l==r){
        t[id].l=l;
        t[id].r=r;
        t[id].s=1;
        Q[make_pair(l,r)]=id;
        return ;
    }
    int mid=(l+r)/2;
    Q[make_pair(l,r)]=id;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id].s=1;
}
void up(int id){
    t[id].s=0;
}
int query(int id,int l,int r,int al,int ar){
    int sum=(t[id].s==1?1:0),mid=(l+r)/2;
    if(al<=l&&r<=ar){
        if(t[id].s==1) return t[id].s;
        if(mid>=al) sum+=query(id*2,l,mid,al,ar);
        if(mid+1<=ar) sum+=query(id*2+1,mid+1,r,al,ar);
    }
    else{
        if(mid>=al) sum+=query(id*2,l,mid,al,ar);
        if(mid+1<=ar) sum+=query(id*2+1,mid+1,r,al,ar);
    }
    return sum;
}
void solve(){
    int ans=0;
    n=read();
    build(1,1,n);
    for(int i=1;i<=n;i++){
        int o=read(),l=read(),r=read();
        if(o==1){
            up(Q[make_pair(l,r)]);
        }
        else{
            cout <<query(1,1,n,l,r)<<endl;
        }
    }
    return ;
}

signed main(){
    solve();
    return 0;
}