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
int T,n,a[200005];
void solve(){
    int ans=0;
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i+=2){
        ans=max(a[i+1]-a[i],ans);
    }
    cout <<ans<<endl;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}