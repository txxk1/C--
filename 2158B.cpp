#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[400005],t[400005];
void solve(){
    int ans=0,now=0,cnt=0;
    cin >>n;
    for(int i=1;i<=2*n;i++) t[i]=0;
    for(int i=1;i<=2*n;i++) cin >>a[i],t[a[i]]++;
    for(int i=1;i<=2*n;i++){
        if(t[i]==0) continue;
        
        if(t[i]%2==1) ans++,now++;
        else ans+=2,now++,cnt++;
    }
    if(cnt%2!=n%2&&now==cnt) ans-=2;
    cout <<ans<<endl;
    return ;
    //
}
// 3 3
// 2 2
// 8 1 3 6 6
// 1+1+
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
//
// k 进制进位多少次