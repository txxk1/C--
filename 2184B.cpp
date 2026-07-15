#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,m;
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
    cin >>n>>k>>m;
    if(n<k){
        cout <<max(n-m%k,0ll)<<endl;
    }
    else{
        if((m/k)%2==1) cout <<k-m%k<<endl;
        else cout <<n-m%k<<endl;
    }
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}