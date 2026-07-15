#include <bits/stdc++.h>
#define int long long 
#define mod 1000000007
using namespace std;
int T,n,rt;
int l[300005],r[300005],f[300005],fa[300005],dep[300005];
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
void dfs(int x){
    if(l[x]!=0){
        dep[l[x]]=dep[x]+1;
        dfs(l[x]);
    }
    if(r[x]!=0){
        dep[r[x]]=dep[x]+1;
        dfs(r[x]);
    }
}
void solve(){
    queue<int> Q;
    n=read();
    for(int i=1;i<=n;i++){
        f[i]=0;
        fa[i]=0;
    }
    for(int i=1;i<=n;i++){
        l[i]=read();
        r[i]=read();
        fa[l[i]]=i;
        fa[r[i]]=i;
        
    }
    for(int i=1;i<=n;i++){
        if(l[i]==0&&r[i]==0) f[i]=1;
        if(fa[i]==0) rt=i,dep[rt]=1;
    }
    int maxn=-1,maxnid;
    dfs(rt);
    for(int i=1;i<=n;i++){
        if(dep[i]>maxn){
            maxn=dep[i];
            maxnid=i;
        }
    }
    
    for(int i=1;i<=n;i++)cout <<f[i]<<" ";
    cout <<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}