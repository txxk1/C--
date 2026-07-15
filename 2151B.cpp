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
int T,n,m,a[100005],b[100005],nxt[300005],sum[200005],qwq;
char ch[100005];
void solve(){
    n=read(),m=read();
    for(int i=1;i<=n+m;i++) nxt[i]=i+1,a[i]=0,b[i]=0;
    for(int i=1;i<=n;i++) cin >>ch[i];
    for(int i=1;i<=m;i++) a[i]=read();
    for(int i=m;i>=1;i--) nxt[a[i]-1]=nxt[a[i]];
    int cnt=0,now=1;
    for(int i=1;i<=n;i++){
        if(ch[i]=='A'){
            nxt[now]=nxt[++now];
            b[++cnt]=now;
        }
        else {
            now=nxt[now];
            nxt[now-1]=nxt[now];
            b[++cnt]=now;
        }
    }
    sort(a+1,a+1+m);
    sort(b+1,b+1+n);
    qwq=0;
    int i,j;
    for(i=1,j=1;i<=m&&j<=n;){
        if(a[i]<b[j]) sum[++qwq]=a[i],i++;
        if(a[i]==b[j]) sum[++qwq]=a[i],i++,j++;
        if(a[i]>b[j]) sum[++qwq]=b[j],j++;
    }
    if(i<=m) for(int k=i;k<=m;k++) if(a[i]!=a[i-1]) sum[++qwq]=a[i];
    if(j<=n) for(int k=j;k<=n;k++) if(b[j]!=b[j-1]) sum[++qwq]=b[j];
    cout <<qwq<<endl;
    for(int i=1;i<=qwq;i++) cout <<sum[i]<<" ";
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
/*
b +x
a +1



01111110
01111111
*/