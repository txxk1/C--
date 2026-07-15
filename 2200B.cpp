#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[15],f[15][15],nxt[15];
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
    int flag=0;
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        f[i][1]=0;
        //ans+=a[i];
    }
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1]) flag=1;
    }
    if(flag==1) cout <<1<<endl;
    else cout <<n<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}