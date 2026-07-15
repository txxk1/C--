#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll T,a,b,k;
ll gcd(ll x,ll y){
    if(y==0) return x;
    return gcd(y,x%y);
}
ll qpow(ll x,ll y){
    ll s=1ll,now=x;
    while(y){
        if(y%2) s=s*now%mod;
        now=now*now%mod;
        y=y/2;
    }
    return s;
}
void solve(){
    cin >>a>>b>>k;
    cout <<qpow(gcd(a,b),k)<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}