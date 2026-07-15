#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[200005];
inline int read(){
    int s=0,f=-1;
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
    int ans=0,now=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    for(int i=2;i<=n;i++){
        ans+=abs(a[i]-a[i-1]);
    }
    now=max(abs(a[2]-a[1]),abs(a[n]-a[n-1]));
    for(int i=2;i<n;i++){
        now=max(now,abs(a[i]-a[i-1])+abs(a[i]-a[i+1])-abs(a[i+1]-a[i-1]));
    }
    cout <<ans-now<<endl;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}