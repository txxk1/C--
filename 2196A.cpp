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
int sol(int x){
    int sum=0,now=x;
    while(x){
        sum+=x%10;
        x=x/10;
    }
    return sum;
}
void solve(){
    int ans=0;
    n=read();
    for(int i=n+1;i<=n+90;i++){
        if(i-sol(i)==n) ans++;
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}