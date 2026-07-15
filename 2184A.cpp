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
int get(int x){
    if(x==2) return 2;
    if(x==3) return 3;
    if(x==4) return 0;
    return x%2;
}
void solve(){
    int ans=0;
    n=read();
    cout <<get(n)<<endl;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}