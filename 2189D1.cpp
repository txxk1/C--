#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,c;
const int mod=1e9+7;
char a[200005];
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
    int ans=1ll,sum=1ll,res=0;
    n=read(),c=read();
    cin >>a;
    if(a[0]=='0'||a[n-1]=='0'||c==1){
        cout <<-1<<endl;
        return ;
    }
    for(int i=1;i<n;i++){
        if(a[i]=='1'){
            for(int j=res+1;j<=i;j++){
                ans=ans*(j-res)%mod;
                sum=sum*(j-res)%c;
            }
            res=i;
        }
    }
    if(!sum){
        cout <<-1<<endl;
        return ;
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}
//  0  2  1