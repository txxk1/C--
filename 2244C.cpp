#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y;
int a[200005],b[200005];
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
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
void solve(){
    int ans=0,flag=0;
    n=read(),x=read(),y=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        b[a[i]]=i;
    }
    int s=gcd(x,y);
    for(int i=1;i<=n;i++){
        int dis=abs(b[i]-i);
        if(dis==0) continue;
        if(dis%s!=0){
            flag=1;
            break;
        }
    }
    if(flag) cout <<"NO"<<endl;
    else cout <<"YES"<<endl;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}