#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int ans[200005];
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
    int id,x;
}a[200005];
bool cmp(node q,node p){
    return q.x<p.x;
}
void solve(){
    int now=0;
    n=read();
    map<int,int> Q;
    for(int i=1;i<=n;i++){
        a[i].x=read();
        a[i].id=i;
        Q[a[i].x]++;
        ans[i]=0;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=n;i>=1;i--){
        if(Q[a[i].x]%2==1){
            now=a[i].x;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i].x==now) ans[a[i].id]=1;
    }
    for(int i=1;i<=n;i++){
        cout <<ans[i];
    }
    cout <<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}