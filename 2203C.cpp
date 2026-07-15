#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,s,m,cnt;
int t[64],a[64];
inline int read(){
    int s=0,f=1ll;
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
bool check(int x){
    int now=s;
    for(int i=cnt;i>=1;i--){
        int len=(1ll<<a[i]);
        int qwq=now/len;
        now-=min(x,qwq)*len;
    }
    if(now==0) return true;
    else return false;
}
void solve(){
    int ans=0;
    cnt=0;
    s=read(),m=read();
    if((s&m)==s){
        cout <<1<<endl;
        return ;
    }
    for(int i=0;i<64;i++){
        int x=(m>>i)&1,y=(s>>i)&1;
        if(x==1) break;
        if(x==0&&y==1){
            cout <<-1<<endl;
            return ;
        }
    }
    for(int i=0;i<64;i++){
        t[i]=(m>>i)&1;
        if(t[i]==1) a[++cnt]=i;
    }
    int l=1ll,r=s;
    while(l<r){
        // fff tttt
        int mid=(l+r)/2;
        if(check(mid)==false) l=mid+1;
        else r=mid-1;
    }
    for(int i=l-2;i<=l+2;i++){
        if(check(i)){
            ans=i;
            break;
        }
    }
    cout <<ans<<endl;
    return ;
}
// s&m==s n=1
//
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}