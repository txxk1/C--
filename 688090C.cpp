
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
    n=read(),m=read();
    if(n>m){
        int p = m;
        m = n;
        n = p;
    }
    if(m%2==0){
        if(n%2==0){
            cout<<(m+n)/2;
            return;
        }
        else {
            cout<<(m/2+(n+1)/2);
            return;
        }
    }
    else {
        if(n%2==0){
            cout<<(n/2+(m+1)/2);
            return;
        }
        else {
            cout<<(m+n)/2;
            return;
        }
    }
}
signed main(){
    solve();
    return 0;
}