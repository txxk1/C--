#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[400005],l,r,s[400005];
void solve(){
    int sum=0;
    cin >>n>>l>>r;
    for(int i=1;i<=n;i++) s[i]=i;
    s[r]=s[l-1];
    for(int i=1;i<=n;i++){
        cout <<(s[i]^s[i-1])<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}