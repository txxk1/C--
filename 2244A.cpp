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
    n=read();
    cin >>a;
    for(int i=0;i<n;i++){
        int now=i;
        while(a[now]=='#') now++;
        ans=max(ans,now-i); 
    }
    cout << (ans+1)/2 << endl;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}