#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,p,q;
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
    int ans=0;
    p=read(),q=read();
    // p 2
    // q 3
    // p<q p--
    if(p*3ll==q*2ll){
        cout <<"Bob"<<endl;
        return ;
    }
    // q--
    if(p>=q){
        cout <<"Alice"<<endl;
        return ;
    }
    else{
        int x=q-p;
        if(p*3ll>q*2ll) cout <<"Bob"<<endl;
        else cout <<"Alice"<<endl;

    }
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}