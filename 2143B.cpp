#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[200005],b[200005],ans,now;
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}
void solve(){
    ans=0;
    n=read(),k=read();
    for(int i=1;i<=n;i++) a[i]=read(),ans+=a[i];
    for(int i=1;i<=k;i++) b[i]=read();
    sort(b+1,b+1+k);
    sort(a+1,a+1+n);
    now=n;
    for(int i=1;i<=k;i++){
        int to=now-b[i]+1;
        if(to>0){
            ans-=a[to];
            now=to-1;
        }
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
