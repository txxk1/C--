#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,h[200005],f[200005];
/*
f[i][0] 前i个数 第i次0/1 分组/没分组 的 ans

*/
void solve(){
    cin >>n;
    for(int i=1;i<=n;i++) cin >>h[i];
    f[1]=h[1];
    for(int i=2;i<=n;i++){
        f[i]=min(f[i-1]+h[i]-1,f[i-2]+h[i-1]+max(0ll,h[i]-(i-1)));
    }
    cout <<f[n]<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}