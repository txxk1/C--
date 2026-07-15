#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,a[200005];
void solve(){
    int cnt=0,sum=0,maxn=-1;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        sum+=a[i];
        maxn=max(maxn,a[i]);
        if(a[i]!=0) cnt++;
    }
    // sum>=ans+n-1
    // sum-n+1
    cout <<min(cnt,sum-n+1)<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}