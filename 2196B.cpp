#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int p[200005],a[200005];
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
vector<int> Q[200005];
void solve(){
    int now=1;
    n=read();
    
    for(int i=1;i<=n;i++) p[i]=read(),Q[i].clear();
    for(int i=1;i<=n;i++){
        a[i]=read();
        Q[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<Q[p[i]].size();j++){
            if(Q[p[i]][j]!=now){
                cout <<"NO"<<endl;
                return ;
            }
            now++;
        }
    }
    cout <<"YES"<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}