#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[200005],t[200005],s[200005];
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
    n=read(),k=read();
    for(int i=0;i<=n;i++) t[i]=0,s[i]=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        s[a[i]]++;
    }
    for(int i=0;i<k-1;i++){
        if(s[i]==0){
            cout <<i<<endl;
            return ;
        }
    }
    cout <<k-1<<endl;
    return ;
}
/*

*/
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}