#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x;
int sx,sy,ex,ey;
int f(int x){
    return x*x;
}
void solve(){
    cin >>n;
    int sum=0,maxn=-1;
    cin >>sx>>sy>>ex>>ey;

    for(int i=1;i<=n;i++){
        cin >>x;
        maxn=max(maxn,x);
        sum+=x;
    }
    int now=f(ex-sx)+f(ey-sy);
    if(sum*sum<now) cout <<"NO"<<endl;
    else if(sum-maxn<maxn&&f(maxn-sum+maxn)>now)cout <<"NO"<<endl;
    else cout <<"YES"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// maxn>minn+d