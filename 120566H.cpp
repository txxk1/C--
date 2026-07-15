#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
int a[100005],b[100005],s[2050],t[2050];
inline int read(){
    int s=0ll,f=1ll;
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
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) b[i]=read();
    t[0]=1;
    t[b[1]]=1;
    vector<int> Q[2050];
    for(int i=1;i<=n;i++) Q[i].push_back(0);
    Q[1].push_back(b[1]);
    for(int i=2;i<=n;i++){
        for(int j=0;j<2048;j++) t[j]=0;
        for(int j=0;j<Q[i-1].size();j++){
            t[max(0ll,Q[i-1][j]-a[i])]=1;
            t[Q[i-1][j]^b[i]]=1;
        }
        for(int j=0;j<2048;j++){
            if(t[j]==1) Q[i].push_back(j);
        }
    }
    for(int i=0;i<Q[n].size();i++){
        ans=max(ans,Q[n][i]);
    }
    cout <<ans;
    
    return ;
}
signed main(){
    solve();
    return 0;
}
/*
0 1 0
2 2 6
*/