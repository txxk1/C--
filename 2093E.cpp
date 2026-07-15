#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,cnt,a[200005],t[200005];
bool check(int x){
    int sum=0,cnt=0;
    for(int j=0;j<x;j++) t[j]=0;
    for(int i=1;i<=n;i++){
        if(a[i]>x) continue;

        if(t[a[i]]==0&&a[i]<x){
            t[a[i]]=1;
            cnt++;
        }
        if(cnt==x){
            sum++;
            cnt=0;
            for(int j=0;j<x;j++) t[j]=0;
        }
    }
    return sum>=k;
}
void solve(){
    cin >>n>>k;
    for(int i=1;i<=n;i++) cin >>a[i];
    int l=0,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    for(int i=l+2;i>=l-2;i--){
        if(check(i)){
            cout <<i<<endl;
            return ;
        }
    }
    cout <<0<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}