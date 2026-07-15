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
    int ans=0,flag=0;
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        ans+=a[i];
        if(ans<i*(i+1)/2){
            flag=1;
        }
    }
    if(flag) cout <<"NO"<<endl;
    else cout <<"YES"<<endl;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}