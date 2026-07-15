#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int qpow(int x,int y){
    int now=x,s=1ll;
    for(int i=1;i<=y;i++){
        s=s*x;
        if(s>n) return n+1;
    }
    return s;
}
bool check(int x){
    int s=qpow(x,k);
    return s<=n;
}
void solve(){
    int ans=0;
    cin >>n>>k;
    if(k>30){
        cout <<1<<endl;
        return ;
    }
    int l=1ll,r=1000000000ll;
    while(l<r){
        int mid=(l+r)/2;
        //  tttt ffff
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    for(int i=max(1ll,l-2);i<=l+2;i++){
        if(check(i)) ans=i;
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}