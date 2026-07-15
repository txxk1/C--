#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,s[10];
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
    s[1]=1;
    s[2]=3;
    s[3]=4;
    s[0]=-1;
    n=read();
    if(n==1){
        cout <<0<<endl;
        return ;
    }
    int now=1,ans=0;
    int t=(n-1)/4;
    ans=t*6;
    int res=n-1-t*4;
    cout <<ans+s[res]<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}