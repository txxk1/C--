#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,k,a[200005],b[200005];
void solve(){
    cin >>n>>k;
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=n;i++) cin >>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    int now=n;
    for(int i=1;i<=n;i++){
        int qwq=a[i]*(b[now]+1)+b[now];
        if(qwq<=k) now--;
    }
    cout <<n-now<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}