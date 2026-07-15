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
    int x=read(),y=read();
    int qwq=abs(x+y);
    if(qwq%3==0&&(x>=y*2&&x>=(-4)*y)) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}