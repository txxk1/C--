#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,cnt;
int a[100005],prime[100005],p[200005];
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
    for(int i=1;i<=n;i++){
        a[i]=1;
    }
    for(int i=2;i<=n;i++){
        a[i-1]=a[i-1]*prime[i];
        a[i]=a[i]*prime[i];
    }
    for(int i=1;i<=n;i++) cout <<a[i]<<" ";
    cout <<endl;
}
signed main(){
    for(int i=2;i<=200000;i++){
        if(p[i]==0) prime[++cnt]=i;
        if(!p[i]){
            for(int j=i;j<=200000;j+=i){
                p[j]=1;
            }
        }
    }
    T=read();
    while(T--) solve();
    return 0;
}