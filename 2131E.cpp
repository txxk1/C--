#include <bits/stdc++.h>

using namespace std;
int T,n,a[200005],b[200005];
void solve(){
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=n;i++) cin >>b[i];
    a[n+1]=0;
    b[n+1]=0;
    for(int i=n;i>=1;i--){
        if(a[i]==b[i]) continue;
        if((a[i]^a[i+1])==b[i]) continue;
        if((a[i]^b[i+1])==b[i]) continue;
        cout <<"NO"<<endl;
        return ;
    }
    cout <<"YES"<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}