#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[200005],t[200005],cnt,ans[200005];
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
    cnt=0;
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i]!=i){
            if(i>a[i]){
                if(i%a[i]!=0||__builtin_popcount(i/a[i])!=1) flag=1;

            }
            else{
                if(a[i]%i!=0||__builtin_popcount(a[i]/i)!=1) flag=1;
            }
        }
        else t[i]=1;
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