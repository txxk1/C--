#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,s,t,a[500005];
void solve(){
    cin >>n>>s>>t;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    if(s==t){
        cout <<0<<endl;
        return ;
    }
    if(s!=1) swap(a[1],a[s]);
    if(t!=n) swap(a[t],a[n]);
    int x=(a[1]&a[n]),y=(a[1]|a[n]),z=(a[1]^a[n]);
    cout <<x+y+z<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}