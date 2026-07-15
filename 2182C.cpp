#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[5005],b[5005],c[5005],f[15005];
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
int work(int x){
    if(x>n) return x-n;
    else return x;
}
void solve(){
    n=read();
    for(int i=1;i<=3*n;i++) f[i]=0;
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) b[i]=read();
    for(int i=1;i<=n;i++) c[i]=read();
    int ans=0,sum=0;
    for(int i=1;i<=n;i++){
        int flag=1;
        for(int j=1;j<=n;j++){
            if(b[work(i+j)]<=a[j]) flag=0;
        }
        ans+=flag;
    }
    for(int i=1;i<=n;i++){
        int flag=1;
        for(int j=1;j<=n;j++){
            if(c[work(i+j)]<=b[j]) flag=0;
        }
        sum+=flag;
    }
    cout <<ans*sum*n<<endl;
}
// f[i] f[i-1]
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}