#include <bits/stdc++.h>
#define inf 1e9+7
#define int long long
using namespace std;
int T,n,m,s1[200005][32];
inline int read(){
    int s=0,f=-1;
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
    cin >>n>>m;
    for(int i=1;i<=m;i++){
        int l,r;
        cin >>l>>r;

    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}