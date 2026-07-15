#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[200003],b[200003],cnta,cntb,cnt,ans;

signed main(){
    cin >>m>>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        if(a[i]<0) b[++cntb]=abs(a[i]);
        if(a[i]==0) m--;
        if(a[i]>0) a[++cnta]=a[i];
    }
    sort(a+1,a+1+cnta);
    sort(b+1,b+1+cntb);
    ans=1e9;
    for(int i=1;i<=min(m,cnta);i++){
        if(n-i<=cntb) ans=min(ans,a[i]+b[n-i]+min(a[i],b[n-i]));
    }
    for(int i=1;i<=min(m,cntb);i++){
        if(n-i<=cnta) ans=min(ans,b[i]+a[n-i]+min(b[i],a[n-i]));
    }
    cout <<ans;
    return 0;
}