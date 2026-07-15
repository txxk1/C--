#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,a[200005],s[200005],t[200005];
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<1)+(s<<3)+(ch-'0');
        ch=getchar();
    }
    return s*f;
}
void solve(){
    n=read();
    m=read();
    int X=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        t[a[i]]++;
        X=max(X,a[i]);
    }
    if(X==1){
        cout <<n<<endl;
        t[1]=0;
        return ;
    }
    for(int i=1;i<=X;i++) s[i]=s[i-1]+t[i];
    int ans=-1e18;
    for(int i=2;i<=X;i++){
        int sum=0;
        for(int j=1;j*i-i<=X;j++){
            int l=(j-1)*i+1;
            int r=min(j*i,X);
            int cnt=s[r]-s[l-1];
            sum+=cnt*j;
            sum-=m*max(0ll,cnt-t[j]);
        }
        ans=max(ans,sum);
    }
    cout <<ans<<endl;
    for(int i=1;i<=X;i++) t[i]=0;
    return ;
}

signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}