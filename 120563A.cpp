#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[100005];
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
    n=read();
    for(int i=1;i<=10;i++){
        if(i*(i+1)==n){
            cout <<"YES"<<endl;
            return ;
        }
    }
    cout <<"NO"<<endl;
    return ;
}
signed main(){
    solve();
    return 0;
}