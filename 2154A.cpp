#include <bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;
int T,n,k;
char a[1005];
void solve(){
    int ans=0,sum=0;
    cin >>n>>k;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]=='0') sum++;
        else{
            if(sum>=k-1){
                ans++;
            }
            if(i<k){
                if(sum==i-1) ans++;
            }
            sum=0;
        }
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}