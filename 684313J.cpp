#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[1005];
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
    int ans=0,now=0;
    n=read();
    int nxt=n;
    while(1){
        int flag=0;
        if(n%2==1){
            a[++ans]=(1ll<<now);
            //n+=(1ll<<now);
            flag=1;
        }
        n=n/2;
        if(flag==1) n++;
        now++;
        if(n==1) break;
    }
    for(int i=1;i<=ans;i++){
        nxt+=a[i];
    }
    int sum=0,qwq=nxt;
    while(1){
        sum++;
        nxt=nxt/2;
        if(nxt==1) break;
    }
    if(sum%2==1) a[++ans]=qwq;
    cout <<ans<<endl;
    for(int i=1;i<=ans;i++) cout <<a[i]<<" ";
    cout <<endl;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}