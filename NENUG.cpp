#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int T,n,m,c,r,k;
int a[200005];

inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+(ch-'0');
        ch=getchar();
    }
    return s*f;
}
void solve(){
    int ans=0ll;
    //cin >>n>>m>>c>>r>>k;
    n=read();
    m=read();
    c=read();
    r=read();
    k=read();
    for(int i=1;i<=k;i++){
        int x,y;
        //cin >>x>>y;
        x=read();
        y=read();
        ans+=abs(x-c)*10ll;
        
        int cnt=min(r+y,m*2+2-r-y);
        if(x!=c) ans+=cnt*3ll;
        else ans+=abs(r-y)*3ll;
        c=x;
        r=y;
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
//