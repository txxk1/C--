#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int T,n,k;
char a[200005];
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return s*f;
}
int qpow(int x,int y){
    int s=1ll,now=x;
    while(y){
        if(y%2) s=s*now%mod;
        now=now*now%mod;
        y=y/2;
    }
    return s;
}
void solve(){
    int ans=0;
    cin >>n;
    cin >>a+1;
    for(int i=n;i>1;i--){
        if(a[i]=='1') ans=(ans+1)*qpow(2,mod-2)%mod;
        else ans=ans*qpow(2,mod-2)%mod;
    }
    cout <<(n-1+ans)%mod<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
/*
1
8
(())(())
*/