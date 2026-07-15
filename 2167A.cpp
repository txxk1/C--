#include <bits/stdc++.h>

using namespace std;
int T,n,k;
int a[5];
void solve(){
    for(int i=1;i<=4;i++) cin >>a[i];
    sort(a+1,a+5);
    if(a[1]==a[4]) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}