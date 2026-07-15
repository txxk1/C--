#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
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
struct node{
    int id,x,col;
}a[105],b[105];
bool cmp(node q,node p){
    return q.x<p.x;
}
void solve(){
    int ans=0,sum=0;
    n=read();
    for(int i=1;i<=n;i++){
        a[i].x=read();
        a[i].id=i;
        a[i].col=i%2;
        b[i]=a[i];
        b[i].col^=1;
    }
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);
    int flaga=1,flagb=1;
    for(int i=1;i<n;i++){
        if(a[i].col+a[i+1].col!=1){
            flaga=0;
        }
        if(b[i].col+b[i+1].col!=1){
            flagb=0;
        }
    }
    if(flaga+flagb==0) cout <<"NO"<<endl;
    else cout <<"YES"<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}