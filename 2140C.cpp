#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,a[200005],s1[200005],s2[200005];
void solve(){
    int sum=0,ans;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        if(i%2==1) sum+=a[i];
        else sum-=a[i];
        s1[i]=i+a[i]*2ll;
        s2[i]=i-a[i]*2ll;
    }
    if(n%2==1) ans=n-1ll;
    else ans=n-2ll;
    int minn=1e18,now=-1e18;
    for(int i=1;i<n;i+=2){
        minn=min(minn,s1[i]);
        now=max(now,s1[i+1]-minn);
    }
    minn=1e18;
    for(int i=2;i<n;i+=2){
        minn=min(minn,s2[i]);
        now=max(now,s2[i+1]-minn);
    }
    cout <<sum+max(now,ans)<<endl;
    return ;
}
signed main(){
    //init();
    cin >>T;
    while(T--) solve();
    return 0;
}
// +a[r]-a[l]
// -a[r]+a[l]
// [l,r] sum+=(r-l) r%2==l%2
//            (r-l)-(a[r]-a[l])*2 r%2==1 , l%2==0
//            (r-l)+(a[r]-a[l])*2 r%2==0 , l%2==1
//            r-a[r]*2  l-a[]
//            r+a[r]*2  l+a[l]*2