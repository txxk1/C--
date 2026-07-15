#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[300005];
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
    int ans=0;
    n=read();
    int now=n+1;
    for(int i=1;i<=n;i++){
        a[i*3-2]=i;
        a[i*3-1]=3*n+2-i*2;
        a[i*3]=3*n+1-i*2;
    }
    for(int i=1;i<=3*n;i++){
        cout <<a[i]<<" ";
    }
    cout <<endl;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}