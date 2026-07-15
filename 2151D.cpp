#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int read(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
    return k*f;
}
int T,n,a[200005],j[200005],s[200005],inv[200005],invj[200005];
void init(){
    j[0]=1;
    invj[0]=1;
    j[1]=1;
    inv[1]=1;
    invj[1]=1;
    for(int i=2;i<=200000;i++){
        j[i]=j[i-1]*i%mod;
        inv[i]=mod-(mod/i)*(inv[mod%i])%mod;
        invj[i]=invj[i-1]*inv[i]%mod;
    }
    return ;

}
int C(int x,int y){
    return (j[x]*invj[y]%mod)*invj[x-y]%mod;
}
void solve(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    s[n]=a[n];
    for(int i=n;i>=1;i--) s[i-1]=s[i]+a[i-1];
    int t=(n+1)/2;
    if(a[1]<2||s[1]!=n){
        cout <<0<<endl;
        return ;
    }
    for(int i=t+1;i<=n;i++){
        if(a[i]!=0){
            cout <<0<<endl;
            return ;
        }
    }
    for(int i=2;i<=t;i++){
        if(a[i]>n+2-i*2){
            cout <<0<<endl;
            return ;
        }
    }
    int ans=1;
    for(int i=t;i>=1;i--){
        ans=ans*(C(n+2-2*i-s[i+1],a[i]))%mod;
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    init();
    cin >>T;
    while(T--) solve();
    return 0;
}
