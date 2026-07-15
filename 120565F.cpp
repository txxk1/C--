#include <bits/stdc++.h>
#define int long long
using namespace std;
int TT,n,a,b,f[60];
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
void solve(){
    cin >>n>>a>>b;
    int T=56;
    int Tmax=max(a*8,max(b*28,(a+b)*7));
    f[2]=b;
    for(int i=3;i<=56;i++){
        f[i]=max(f[i-2]+b,f[i-1]);
        if(i>=7) f[i]=max(f[i-7]+a,f[i]);
        if(i>=8) f[i]=max(f[i-8]+a+b,f[i]);
    }
    cout <<(n/T)*Tmax+f[n%T]<<endl;
    return ;
}
signed main(){
    cin >>TT;
    while(TT--) solve();
    return 0;
}