#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,a[200005];
void solve(){
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i];
    int now=1e9;
    for(int i=1;i<=n;i++){
        if(a[i]/2>=now){
            //now=a[i]/2;
            cout <<"NO"<<endl;
            return ;
        }
        now=min(now,a[i]);
    }
    cout <<"YES"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
/*
2 1
x y
2 1
x-2 
  y-1
40 40 40
40 
*/