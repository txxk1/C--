#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,a[200005],b[200005];

void solve(){
    int sum=0;
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i],sum=sum^a[i];
    for(int i=1;i<=n;i++) cin >>b[i],sum=sum^b[i];
    if(!sum){
        cout <<"Tie"<<endl;
        return ;
    }
    for(int i=n;i>=1;i--){
        if(a[i]!=b[i]){
            if(i%2==0) cout <<"Mai"<<endl;
            else cout <<"Ajisai"<<endl;
            return ;
        }
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}