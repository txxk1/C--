#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,l,a,b;
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
void solve(){
    int ans=-1;
    cin >>l>>a>>b;
    for(int i=0;i<l;i++){
        int now=(a+i*b)%l;
        ans=max(ans,now);
    }
    cout <<ans<<endl;
    return ;
}
//
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}