#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
int a[200005],b[200005],s[200005],cnt[200005];
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
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        s[i]=s[i-1]+a[i];
        cnt[i]=0;
    }
    //ans=s[n];
    for(int i=1;i<=m;i++){
        b[i]=read();
        //ans=max(ans,s[n]-s[b[i]]*2);
    }
    sort(b+1,b+m+1);
    //b[m+1]=n;
    for(int i=1;i<=m;i++){
        ans+=abs(s[b[i]]-s[b[i-1]]);
    }
    int lst=0;
    /*
    for(int i=1;i<=m;i++){
        if(2*s[lst]>s[b[i]]){
            //ans=s[n]-s[b[i]]*2;
            cnt[b[i]]++;
            lst=b[i];
        }
    }
    int now=0;
    for(int i=1;i<=n;i++){
        now+=cnt[i];
        if(now%2==1) ans-=a[i];
        else ans+=a[i];
    }
    */
    cout <<ans+s[n]-s[b[m]]<<endl;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}