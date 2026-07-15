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
    int x=n,y=n*2ll,z=n*3ll;
    for(int i=0;i<=31;i++){
        int now=(1ll<<i);
        if(now>n){
            ans=now;
            break;
        }
    }
    cout <<ans*n<<" "<<(ans+1)*n<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}
// 11