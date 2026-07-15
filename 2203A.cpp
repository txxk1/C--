#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,d;
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
    int ans=1;
    n=read(),m=read(),d=read();
    for(int i=1;i<=n+1;i++){
        ans=i;
        if(i*m>d){
            ans=i;
            break;
        }
        
    }
    for(int i=1;i<=n;i++){
        if(i*ans>=n){
            cout <<i<<endl;
            return ;
        }
    }
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}