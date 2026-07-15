#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int t[100005];
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
    int flag=0;
    cin >>n;
    for(int i=1;i<=n*n;i++){
        t[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin >>x;
            t[x]++;
        }
    }
    for(int i=1;i<=n*n;i++){
        if(t[i]>n*(n-1)) flag=1;
    }
    if(flag) cout <<"NO"<<endl;
    else cout <<"YES"<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}