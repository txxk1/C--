#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,s,x;
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
    int ans=0;
    n=read(),s=read(),x=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        ans+=a[i];
    }
    int res=s-ans;
    if(res<0){
        cout <<"NO"<<endl;
        return ;
    }
    if(res%x==0){
        cout <<"YES"<<endl;
        return ;
    }
    else cout <<"NO"<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}
// an^(n-1)==an-1