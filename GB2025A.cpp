#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
char a[100005];
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
    cin >>a;
    for(int i=0;i<strlen(a);i++){
        if(a[i]=='Y') ans++;
    }
    if(ans>1) cout <<"NO"<<endl;
    else cout <<"YES"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}