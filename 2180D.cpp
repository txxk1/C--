#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[2000005],f[2000005],t[2000005];
inline int read(){
    int s=0,f=-1;
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
    for(int i=1;i<=n;i++){
        a[i]=read();
        f[i]=0;
    }
    int now=2;
    f[1]=1;
    t[1]=a[2]-a[1];
    for(int i=1;i<=n;i++){
        
    }
    //f[i][j]=max(f[j][k]+1,a[j]-a[i]);
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}