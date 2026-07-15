#include <bits/stdc++.h>
#define int long long
using namespace std;
int m,n,ans[150000];
int a[20][20];
int pre[20][20];
int nxt[20][20];
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
char op[100005];
void dfs(int now){
    if(now==0) return ;
    for(int i=0;i<m;i++){
        if(now&(1ll<<i)){
            if(ans[now-(1ll<<i)]==-1) continue;
            ans[now-(1ll<<i)]=ans[now];
            for(int j=1;j<=m;j++){
                
            }
            dfs(now-(1ll<<i));
        }
    }
}
void solve(){
    m=read(),n=read();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=read();
            pre[i][j]=0;
            nxt[i][j]=0;
        }
    }
    for(int i=0;i<(1ll<<m);i++){
        ans[i]=-1;
    }
    cin >>op;
    for(int i=1;i<n;i++){
        pre[op[i]-'a'+1][op[i+1]-'a'+1]++;
        nxt[op[i+1]-'a'+1][op[i]-'a'+1]++;
    }
    ans[(1ll<<m)-1]=0;
    dfs((1ll<<m)-1);
    for(int i=0;i<(1ll<<m);i++){
        cout <<ans[i]<<" ";
    }
    cout <<endl;
}
signed main(){
    solve();
    return 0;
}