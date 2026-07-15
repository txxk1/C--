#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200005],s1[200005],s2[200005],v[200005];
void solve(){
    cin >>n;
    int now=0;
    s1[0]=1e9;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        s1[i]=min(s1[i-1],a[i]);
    }
    s2[n+1]=-1;
    for(int i=n;i>=1;i--) s2[i]=max(s2[i+1],a[i]);
    for(int i=2;i<n;i++){
        if(s1[i-1]>a[i]&&a[i]>s2[i+1]){
            cout <<"NO"<<endl;
            return ;
        }
        if(s1[i-1]<a[i]&&a[i]<s2[i+1]) now=1;
    }
    if(now) cout <<"NO"<<endl;
    else cout <<"YES"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}