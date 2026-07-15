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
    cin >>n;
    cin >>a;
    for(int i=n;i<2*n;i++) a[i]=a[i-n];
    for(int i=0;i<n;i++){
        int now=i,sum=0;
        while(now<=i+n-1){
            int qwq=now+1;
            sum++;
            while(a[qwq]==a[now]) qwq++;
            now=qwq;
        }
        ans=max(ans,sum);
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}