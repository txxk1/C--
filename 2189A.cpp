#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,h,l;
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
    int ans=0,sum=0;
    n=read(),h=read(),l=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i]<=l) ans++;
        if(a[i]<=h) sum++;
    }
    if(h==l){
        cout <<ans/2<<endl;
        return ;
    }
    if(ans<sum) swap(ans,sum);
    int answ=0;
    for(int i=1;i<=n;i++){
        if(i<=sum&&2*i<=ans) answ=i;
    }
    cout <<answ<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}