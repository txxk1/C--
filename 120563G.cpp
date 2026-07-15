#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
int a[100005],b[100005];
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
    int ans=0ll,sum=0ll;
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        ans+=a[i];
    }
    for(int i=1;i<=m;i++){
        b[i]=read();
        sum+=b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    if(ans==sum){
        cout <<1<<endl;
        return ;
    }
    if(ans>sum){
        int qwq=0ll;
        for(int i=n;i>=1;i--){
            ans-=a[i];
            if(ans<=sum){
                cout <<n-i+1<<endl;
                return ;
            }
        }
    }
    else{
        for(int i=m;i>=1;i--){
            sum-=b[i];
            if(sum<=ans){
                cout <<m-i+1<<endl;
                return ;
            }
        }
    }
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}