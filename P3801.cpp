#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q;
inline int read(){
    int s=0,f=1ll;
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
struct smt{
    int t[400005];
    void build(int x,int l,int r){
        if(l==r){
            t[x]=0;
            return ;
        }
        int mid=(l+r)/2;
        build(x*2,l,mid);
        build(x*2+1,mid+1,r);
        t[x]=t[x*2]+t[x*2+1];
    }
    void change(int x,int l,int r,int pos){
        if(l==r){
            t[x]=t[x]^1;
            return ;
        }
        int mid=(l+r)/2;
        if(pos<=mid) change(x*2,l,mid,pos);
        if(mid+1<=pos) change(x*2+1,mid+1,r,pos);
        t[x]=t[x*2]+t[x*2+1];
        return ;
    }
    int query(int x,int l,int r,int al,int ar){
        int ans=0;
        if(al<=l&&r<=ar){
            return t[x];
        }
        int mid=(l+r)/2;
        if(al<=mid) ans+=query(x*2,l,mid,al,ar);
        if(mid+1<=ar) ans+=query(x*2+1,mid+1,r,al,ar);
        //t[x]=t[x*2]+t[x*2+1];
        return ans;
    }
}X,Y;
void solve(){
    n=read(),m=read(),q=read();
    X.build(1,1,n);
    Y.build(1,1,m);
    while(q--){
        int op=read();
        if(op==1){
            int x=read(),y=read();
        
            X.change(1,1,n,x);
            Y.change(1,1,m,y);
        }
        else{
            int ax=read(),ay=read(),bx=read(),by=read();
        
            int A=X.query(1,1,n,ax,bx);
            int B=Y.query(1,1,m,ay,by);
            int sum=0;
            cout <<A*(by-ay+1)+B*(bx-ax+1)-A*B*2<<endl;
        }
    }
    return ;
}
signed main(){
    //freopen("P3801_1.in","r",stdin);
    solve();
    return 0;
}