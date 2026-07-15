#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[100005];
void solve(){
    cin >>n>>k;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        int x=a[i]%(k+1);
        a[i]=a[i]+x*k;
    }
    for(int i=1;i<=n;i++) cout <<a[i]<<" ";
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}