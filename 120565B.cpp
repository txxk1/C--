#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
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
    int ans=0;
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i+j)%2==0) cout <<"/";
            else cout <<'\\';
        }
        cout <<endl;
    }
    return ;
}
signed main(){
    solve();
    return 0;
}