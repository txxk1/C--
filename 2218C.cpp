#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[100005];
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
    int ans=0,maxn=-100;
    for(int i=1;i<=7;i++){
        a[i]=read();
        ans+=a[i];
        maxn=max(maxn,a[i]);
    }
    cout <<maxn*2-ans<<endl;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}