#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int p[100005],prime[100005],cnt;
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
    int ans=1;
    n=read();
    for(int i=1;i<=cnt;i++){
        if(n%prime[i]==0){
            ans=ans*prime[i];
            while(n%prime[i]==0) n=n/prime[i];
            //cout <<ans<<endl;
        }
    }
    ans=ans*n;
    cout <<ans<<endl;
    return ;
}
signed main(){
    for(int i=2;i<=100000;i++){
        if(p[i]==0) prime[++cnt]=i;
        for(int j=i;j<=100000;j+=i){
            p[j]=1;
        }
    }
    //for(int i=1;i<=100;i++) cout <<prime[i]<<endl;
    T=read();
    while(T--) solve();
    return 0;
}