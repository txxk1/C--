#include <bits/stdc++.h>
#define inf 2e9
#define int long long
using namespace std;
int T,n,k,maxn[200005];
struct node{
    int a,b;
}e[200005];
bool cmp(node x,node y){
    return x.b<y.b;
}
void solve(){
    int ans=0ll;
    int sum=inf;
    cin >>n>>k;
    for(int i=1;i<=n;i++) cin >>e[i].a;
    for(int i=1;i<=n;i++){
        
        cin >>e[i].b;
        if(e[i].b<e[i].a) swap(e[i].b,e[i].a);
    }
    sort(e+1,e+1+n,cmp);
    for(int i=1;i<=n;i++){
        ans+=abs(e[i].a-e[i].b);
        
    }
    int now=0;
    for(int i=1;i<n;i++){
        if(e[i+1].a<e[i].b){
            cout <<ans<<endl;
            return ;
        }
        sum=min(sum,2*(e[i+1].a-e[i].b));
    }
    cout <<ans+sum<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// a b a b
// abba
// baba