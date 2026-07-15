#include <bits/stdc++.h>
#define int long long
#define inf 1e9
using namespace std;
int T,n;
int a[300005],s[300005],t[300005];
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
    n=read();
    for(int i=1;i<=n;i++){
        s[i]=inf;
        t[i]=0;
    }
    for(int i=1;i<=n;i++){
        a[i]=read();
        s[a[i]]=1;
        t[a[i]]++;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                if(s[j]==-1||s[i/j]==-1) continue;
                s[i]=min(s[i],s[j]+s[i/j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i]!=inf) cout <<s[i]<<" ";
        else cout <<-1<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}
// an^(n-1)==an-1