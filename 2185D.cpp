#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,h,a[200005],add[200005];
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
int b[200005],c[200005];
void solve(){
    cin >>n>>m>>h;
    for(int i=1;i<=n;i++) cin >>a[i],add[i]=0;
    for(int i=1;i<=m;i++) cin >>b[i]>>c[i];
    int l=1,r=1;
    while(r<=m){
        add[b[r]]+=c[r];
        if(a[b[r]]+add[b[r]]>h){
            for(int i=l;i<=r;i++) add[b[i]]-=c[i];
            l=r+1;
        }
        r++;
    }
    for(int i=1;i<=n;i++){
        cout <<a[i]+add[i]<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}