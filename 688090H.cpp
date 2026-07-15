#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
int deg[1000005],in[1000005],a[1000005],cnt,t[1000005];
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
int get(int x,int y){
    return (x&y)*(x^y)*(x|y);
}
void solve(){
    int ans=0;
    n=read(),m=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        deg[x]++;
        deg[y]++;
    }        
    for(int i=1;i<=n;i++){
        t[deg[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(in[deg[i]]==0){
            a[++cnt]=deg[i];
            in[deg[i]]=1;
        }
        
    }
    for(int i=1;i<=cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            ans+=t[a[i]]*t[a[j]]*get(a[i],a[j]);
        }
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    solve();
    return 0;
}