#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
int a[105][105],mi[20],mx[20];
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
            cin >>a[i][j];
        }
    }
    int now=10000;
    for(int i=1;i<=m;i++) now=min(now,a[1][i]);
    for(int i=2;i<=n;i++){
        int qwq=10000;
        for(int j=1;j<=m;j++){
            if(a[i][j]>now){
                if(a[i][j]<qwq){
                    qwq=a[i][j];
                }
            }
        }
        if(qwq==10000){
            cout <<"NO"<<endl;
            return ;
        }
        now=qwq;
    }
    cout <<"YES"<<endl;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}