#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,t[50];
char a[100005];
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
int L(int x){
    return (x+n-2)%n+1;
}
int R(int x){
    return (x)%n+1;
}
void dfs(int now,int dep){
    if(dep==n+1) return ;
    t[now]=1;
    if(a[now-1]=='R') dfs(R(now),dep+1);
    else dfs(L(now),dep+1);
}
void solve(){
    int ans=0;
    n=read();
    for(int i=1;i<=n;i++) t[i]=0;
    cin >>a;
    dfs(1,1);
    for(int i=1;i<=n;i++){
        if(t[i]==1) ans++;
    }
    cout <<ans<<endl;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}