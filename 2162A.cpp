#include <bits/stdc++.h>

using namespace std;
int T,n,a[1005];
void solve(){
    int ans=-1;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        ans=max(ans,a[i]);
    }
    cout <<ans<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}