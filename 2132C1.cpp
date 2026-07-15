#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,s[105],now;

void solve(){
    cin >>n>>k;
    int ans=n*3;
    for(int i=now;i>=0;i--){
        while(n>=s[i]){
            ans+=s[i-1]*i;
            n-=s[i];
        }
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    s[0]=1ll;
    for(int i=1;i<=100;i++){
        s[i]=s[i-1]*3ll;
        now=i;
        if(s[i]>1e9) break;
    }

    cin >>T;
    while(T--) solve();
    return 0;
}
//  3 -> x=1 +1
//  9 -> x=2 +6
//