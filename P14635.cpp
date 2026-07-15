#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,k,a[200005],b[200005],f[400005];
struct node{
    int x,id,p;
    bool operator < (const node &a)const{
        return a.x<x;
    }
};
void solve(){
    priority_queue<node> Q;
    T=1e18;
    cin >>n>>k;
    for(int i=1;i<=n;i++) cin >>a[i]>>b[i];
    for(int i=1;i<=n;i++){
        T=min(T,a[i]+b[i]);
        Q.push((node){a[i],i,0});
        //Q.push()
    }
    int ans=0;
    for(int i=1;i<=n*2;i++){
        node now=Q.top();
        Q.pop();
        f[i]=ans+now.x;
        ans=ans+now.x;
        if(now.p==0){
            Q.push((node){b[now.id],now.id,1});
        }
    }
    ans=0;
    for(int i=0;i<=n;i++){
        if(f[i]>k) break;
        int res=(k-f[i])/T;
        ans=max(ans,res*2+i);
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    solve();
    return 0;
}