#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[100005],sum;
void solve(){
    sum=0;
    cin >>n>>k;
    for(int i=1;i<=n;i++) cin >>a[i],sum+=a[i];
    sort(a+1,a+1+n);
    int qwq=sum/k,ans=0,now=0;
    for(int i=n;i>=n-qwq+1;i--){
        ans+=a[i];
    }
    cout <<ans<<endl;
    int l=1,r=n;
    while(l<=r){
        while(now+a[r]<k&&l<r){
            now=now+a[l];
            cout <<a[l]<<" ";
            l++;
        }
        now=(now+a[r])-k;
        cout <<a[r]<<" ";
        r--;
    }
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}