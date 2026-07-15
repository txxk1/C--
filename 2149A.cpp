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
int T,n,a[10];
void solve(){
    n=read();
    int now=0,neg=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i]==0) now++;
        if(a[i]==-1) neg++;
    }
    cout <<now+neg%2*2<<endl;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}