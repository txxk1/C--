#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[200005],b[200005];
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
void print(){
    for(int i=1;i<=n;i++) cout <<a[i]<<" ";
    cout <<endl;
}
void solve(){
    int l,r;
    n=read();
    int now=n;
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++){
        if(a[i]!=now){
            l=i;
            break;

        }            
        now--;
    }
    if(now==0){
        print();
        return ;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==now) r=i;
    }
    for(int i=l;i<=r;i++){
        b[i]=a[l+r-i];
    }
    for(int i=l;i<=r;i++) a[i]=b[i];
    print();
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}
// an^(n-1)==an-1