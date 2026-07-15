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
int T,n,m,a[300105],b[300105],nxt[300105],sum[200105],qwq;
char ch[100005];
void solve(){
    n=read(),m=read();
    for(int i=1;i<=2*n+m+10;i++) nxt[i]=i+1,a[i]=0,b[i]=0;

    for(int i=1;i<=n;i++) cin >>ch[i];
    
    for(int i=1;i<=m;i++) a[i]=read();

    for(int i=m;i>=1;i--) if(a[i]<=2*n+m+5) nxt[a[i]-1]=nxt[a[i]];
    int cnt=0,now=1;
    for(int i=1;i<=n;i++){
        if(ch[i-1]=='B'){
            now=nxt[now];
        }
        if(ch[i]=='A'){
            b[++cnt]=++now;
        }
        if(ch[i]=='B'){
            now=nxt[now];
            b[++cnt]=now;
        }
    }    
    sort(b+1,b+1+n);
    a[m+1]=3e9,b[n+1]=3e9;
    qwq=0;
    int i,j;
    for(i=1,j=1;i<=m||j<=n;){
        if(a[i]<b[j]) sum[++qwq]=a[i],i++;
        if(a[i]==b[j]&&a[i]!=3e9) sum[++qwq]=a[i],i++,j++;
        if(a[i]>b[j]) sum[++qwq]=b[j],j++;
    }

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