#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100005],t[400005];
void build(int id,int l,int r){
    if(l==r){
        t[id]=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=t[id*2]+t[id*2+1];
}
void change(int id,int l,int r,int pos,int x){
    if(pos<=l&&pos>=r){
        t[id]+=x;
        return ;
    }
    int mid=(l+r)/2;
    if(pos<=mid) change(id*2,l,mid,pos,x);
    else change(id*2+1,mid+1,r,pos,x);
    t[id]=t[id*2]+t[id*2+1];
}
int query(int id,int l,int r,int pos){
    if(pos<=l&&pos>=r){
        return t[id];
    }
    int mid=(l+r)/2,ans=0;
    if(pos<=mid) ans+=query(id*2,l,mid,pos);
    else ans+=query(id*2+1,mid+1,r,pos);
    t[id]=t[id*2]+t[id*2+1];
    return ans;
}
void solve(){
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int op,pos,x;
        cin >>op;
        if(op==1){
            cin >>pos>>x;
            change(1,1,n,pos,x);
        }
        else{
            cin >>pos;
            cout <<query(1,1,n,pos)<<endl;
        }
    }
    return ;
}
signed main(){
    solve();
    return 0;
}