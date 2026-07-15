#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,a[200005],n,f[200005],vis[200005];
struct node{
    int id,x;
    bool  operator <(const node &a)const{
        return a.x<x;
    }
};
void solve(){
    cin >>n;
    int sum=0;
    for(int i=1;i<=n;i++) cin >>a[i];
    priority_queue<node>Q;
    Q.push((node){n,max(a[1],a[n])});
    f[n]=1;
    for(int i=1;i<n;i++) Q.push((node){i,max(a[i],a[i+1])}),f[i]=i+1;
    while(!Q.empty()){
        node qwq=Q.top();
        Q.pop();
        if(Q.empty()) break;
        sum+=qwq.x;

    }

    cout <<sum<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// 0 0  5
// a[] +x
// +max(x,amax)
// x<amin +amin