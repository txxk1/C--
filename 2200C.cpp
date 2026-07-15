#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,t[5005],nxt[5005];
char a[5005];
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
    int ans=0,cnt=0;
    cin >>n;
    cin >>a;

    for(int i=0;i<n;i++){
        t[++cnt]=i;
        if(cnt>1){
            if(a[t[cnt]]==a[t[cnt-1]]) cnt-=2;
        }
    }
    if(cnt==0) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}