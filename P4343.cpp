#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[100005],l,r,ans1,ans2;
int check(int x){
    int ans=0,now=0;
    for(int i=1;i<=n;i++){
        now=max(0ll,now+a[i]);
        if(now>=x) now=0,ans++;
    }
    return ans;
}
signed main(){
    cin >>n>>k;
    for(int i=1;i<=n;i++) cin >>a[i];
    l=1,r=1e13;
    while(l<=r){
        int mid=(l+r)/2;
        int qwq=check(mid);
        if(qwq<=k){
            r=mid-1;
            if(qwq==k) ans2=mid;
        }
        else  l=mid+1;
    }
    l=1,r=1e13;
    while(l<=r){
        int mid=(l+r)/2;
        int qwq=check(mid);
        if(qwq>=k){
            l=mid+1;
            if(qwq==k) ans1=mid;
        }
        else  r=mid-1;
    }
    if(!ans1) cout <<-1;
    else cout <<ans2<<" "<<ans1;
    return 0;
}