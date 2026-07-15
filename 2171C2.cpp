#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,a[200005],b[200005];

void solve(){
    int flag=0;
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=n;i++) cin >>b[i];
    for(int i=20;i>=0;i--){
        int sum=0;
        for(int j=1;j<=n;j++){
            sum=sum^(a[j]&(1<<i));
            sum=sum^(b[j]&(1<<i));
        }
        if(!sum){
            continue;
        }
        for(int j=n;j>=1;j--){
            if((a[j]&(1<<i))!=(b[j]&(1<<i))){
                if(j%2==0) cout <<"Mai"<<endl;
                else cout <<"Ajisai"<<endl;
                return ;
            }
        }        
    }
    cout <<"Tie"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}