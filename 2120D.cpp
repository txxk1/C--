#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int T,a,b,k;
int qpow(int x,int y){
    int s=1ll,now=x;
    while(y){
        if(y%2) s=s*now%mod;
        now=now*now%mod;
        y=y/2;
    }
    return s;
}
int inv(int x){
    return qpow(x,mod-2);
}
int C(int x,int y){
    int s=1ll;
    for(int i=x;i>=x-y+1;i--){
        s=s*i%mod;
        s=s*inv(x-i+1)%mod;
    }
    return s;
}
// x*(x-1)
void solve(){
    cin >>a>>b>>k;
    int n=((a-1ll)*(k-1ll)%mod+a)%mod;
    cout <<n<<" "<<((C(n,a)*(b-1ll)%mod)*k%mod+1ll)%mod<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// C(n,k)*(b-1)+1
// 