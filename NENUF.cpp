#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int T,n,k;
int a[200005];
bool dfs(int x){
    if(x==n+1) return true;
    for(int i=x;i<=n;i++){
        if(x>=i-a[i]+1){
            if(dfs(x+a[i])==true) return true;
        }
    }
    return false;
}
void solve(){
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i];
    if(dfs(1)) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}