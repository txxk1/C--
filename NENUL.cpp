#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int T,n,k;
int a[200005];
bool check(int x){
    int sum=1ll,now=0ll;
    for(int i=1;i<=n;i++){
        if(a[i]>x) return false;
        now+=a[i];
        if(now>x){
            sum++;
            now=a[i];
        }
    }
    return sum<=k;
}
// FFF TTT
void solve(){
    cin >>n>>k;
    for(int i=1;i<=n;i++) cin >>a[i];
    int l=0ll,r=10000000000000ll;
    while(l<r){
        int mid=(l+r)/2ll;
        if(!check(mid)) l=mid+1ll;
        else r=mid-1ll;
    }
    int ans=0;
    for(int i=l+2;i>=l-2;i--){
        if(check(i)){
            
            ans=i;
        }
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    solve();
    return 0;
}