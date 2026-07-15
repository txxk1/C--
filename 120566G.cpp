#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,l;
int x[200005],y[200005],s[200005],pos[200005];
inline int read(){
    int s=0ll,f=1ll;
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
int find(int x){
    int l=1,r=n,ans=0;
    while(l<r){
        int mid=(l+r)/2;
        //  fff     ttt
        if(s[mid]>x) r=mid-1;
        else l=mid+1;
    }
    for(int i=l+2;i>=l-2;i--){
        if(s[i]>x) ans=s[i];
    }
    return ans;
}
void solve(){
    int ans=0;
    map<int,int >Q;
    n=read(),m=read(),l=read();
    for(int i=1;i<=n;i++) x[i]=read(),s[i]=s[i-1]+x[i];
    for(int i=1;i<=m;i++) y[i]=read();
    for(int i=1;i<=n;i++) Q[s[i]]=1;
    int now=0ll;
    for(int i=1;i<=m;i++){
        now+=y[i];
        if(now>=s[n]) break;
        int x=find(now);
        if(x<now+l){
            cout <<"YES";
            return ;
        }
    }
    cout <<"NO";
    return ;
}
signed main(){
    solve();
    return 0;
}