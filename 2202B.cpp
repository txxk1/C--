#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,f[200005],q[200005],pcnt,qcnt;
char a[200005];
char nxt[200005];
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
    int flag=1;
    cin >>n;
    cin >>a;
    int x=n%2;
    if(x==0) x=2;
    int now=1;
    if(x==2){
        if(a[n-1]==a[n-2]){
            cout <<"NO"<<endl;
            return ;
        }
    }
    for(int i=n-2-x;i>=0;i-=2){
        if(a[i]==a[i+1]&&a[i]!='?'&&a[i]!=a[n-1]){
            flag=0;
        }
    }
    if(flag==1) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
//   aba