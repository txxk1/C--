#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,a[5005];

void solve(){
    cin >>n;
    int x=n/2;
    if(n%2==1){
        cout <<0<<endl;
        return;
    }
    else{
        cout <<n/4+1<<endl;
        return ;
    }
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}