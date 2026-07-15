#include <bits/stdc++.h>
#define int long long

using namespace std;
const int mod=1e9+7;
int T,n,a[305],s[305];
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}
vector<int> f[305];
void solve(){
    // f[i][j] 前i个数子集有j个逆序对的个数

    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        f[a[i]].push_back(i);
    }
    

    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
