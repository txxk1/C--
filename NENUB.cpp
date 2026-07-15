#include <bits/stdc++.h>
#define int long long
#define inf 1000000007
using namespace std;
int T,n;
int f[1005];
void solve(){
    cin >>n;
    int res=n%7,ans=inf;
    for(int i=0;i<7;i++){
        if(res+i*7>n) break;
        if(f[res+i*7]!=inf) ans=min(ans,f[res+i*7]+n/7-i);
    }
    if(ans==inf) cout <<-1<<endl;
    else cout <<ans<<endl;
    return ;
}
signed main(){
    for(int i=1;i<=110;i++) f[i]=inf;
    f[3]=1;
    f[5]=1;
    for(int i=6;i<=110;i++){
        f[i]=min(f[i-3]+1,f[i-5]+1);
    }
    cin >>T;
    while(T--) solve();
    return 0;
}