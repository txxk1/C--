#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
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
    n=read();
    if(n==1) cout <<"FZU"<<endl;
    if(n==2) cout <<"FNU"<<endl;
    if(n==3) cout <<"FZU"<<endl;
    if(n==4) cout <<"FZU"<<endl;
    if(n==5) cout <<"FAFU"<<endl;
    if(n==6) cout <<"HQU"<<endl;
    if(n==7) cout <<"MJU"<<endl;
    if(n==8) cout <<"XMUT"<<endl;
    if(n==9) cout <<"QNU"<<endl;
    if(n==10) cout <<"JMU"<<endl;
    if(n==11) cout <<"FZU"<<endl;
}
signed main(){
    solve();
    return 0;
}