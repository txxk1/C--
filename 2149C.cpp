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
int T,n,k,t[200005];
void solve(){
    int ans=0;
    n=read(),k=read();
    for(int i=0;i<=n;i++) t[i]=0;
    for(int i=1;i<=n;i++) t[read()]++;
    for(int i=0;i<k;i++){
        if(t[i]==0) ans++;
    }
    cout <<max(ans,t[k])<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}