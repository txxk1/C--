#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
struct node{
    int l,r;
}e[100005];
bool cmp(node a,node b){
    if(a.l==b.l) return a.r<b.r;
    return a.l<b.l;
}
void solve(){
    cin >>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        cin >>e[i].l>>e[i].r>>x;
        e[i].r=x-1;
    }
    sort(e+1,e+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(k>e[i].r) continue;
        if(k>=e[i].l) k=max(k,e[i].r+1);
    }
    cout <<k<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
//
// k 进制进位多少次