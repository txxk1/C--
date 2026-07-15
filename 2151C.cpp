#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
    return k*f;
}
int T,n,m,a[400105],b[200005];
void solve(){
    n=read();
    for(int i=1;i<=2*n;i++) a[i]=read();
    b[n+1]=0;
    for(int i=n;i>=1;i--){
        b[i]=-b[i+1]+a[2*n+1-i]-a[i];
    }
    int ans=b[1];
    for(int i=1;i<=n;i++){
        cout <<ans<<" ";
        ans+=2*b[i+1];
    }
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
/*
1
4
6149048 26582657 36124499 43993239 813829899 860114890 910238130 913669539
*/