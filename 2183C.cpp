#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,k;
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
    n=read(),m=read(),k=read();
    if(k-1<n-k) k=n+1-k;
    int a=0,b=0;
    while(1){
        if(a<n-k&&a+1+b+max(a+1,b)-1<=m) a++;
        if(b<k-1&&a+b+1+max(a,b+1)-1<=m) b++;
        else break;
    }
    cout <<a+b+1<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}