#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int T,n,k;
int a[200005];
void debug(){
    cout <<"BUG"<<endl;
}
int qpow(int x,int y){
    int sum=1,now=x;
    while(y){
        if(y%2) sum=sum*now%mod;
        now=now*now%mod;
        y=y/2;
    }
    return sum;
}
int inv(int qwq){
    return qpow(qwq,mod-2);
}
void solve(){
    int x=0ll,y=1ll;
    cin >>n;
    for(int i=1;i<=2*n;i++) cin >>a[i];
    sort(a+1,a+1+2*n);
    //debug();
    // x/y +100/a[i]
    // y*a[i] x*a[i]+y*100
    for(int i=1;i<=2*n;i+=2){
        int qwq=(i+1)/2;
        int qwqx=(x*a[i]+qwq*y%mod*100ll)%mod;
        int qwqy=y*a[i]%mod;
        x=qwqx;
        y=qwqy;
        qwqx=(x*a[i+1]+qwq*y%mod*100ll)%mod;
        qwqy=y*a[i+1]%mod;
        x=qwqx;
        y=qwqy;
    }
    cout <<x*inv(y)%mod<<endl;
    return ;
}
signed main(){
    solve();
    return 0;
}