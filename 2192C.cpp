#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,h,k,a[200005],td,mx[200005],mi[200005];
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
    int maxn=-1;
    td=0;
    n=read(),h=read(),k=read();
    mx[n+1]=0;
    mi[0]=1e9;
    for(int i=1;i<=n;i++){
        a[i]=read();
        td+=a[i];
        //maxn=max(maxn,a[i]);
        mi[i]=0;
        mx[i]=0;
    }
    for(int i=n;i>=1;i--){
        mx[i]=max(mx[i+1],a[i]);
    }
    for(int i=1;i<=n;i++){
        mi[i]=min(mi[i-1],a[i]);
    }
    int res=h%td,now=0,id=-1;
    int qwq=h/td;
    if(res==0){
        cout <<qwq*(n+k)-k<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        now+=a[i];
        int M=now-mi[i]+mx[i+1];
        if(max(now,M)>=res){
            id=i;
            break;
        }
    }
    cout <<qwq*(n+k)+id<<endl;
    // T=n+k sum
    // h<=0
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}