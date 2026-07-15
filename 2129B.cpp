#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[5005];

void solve(){
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=0,r=0;
        for(int j=1;j<i;j++){
            if(a[j]>a[i]) l++; 
        }
        for(int j=i+1;j<=n;j++){
            if(a[j]>a[i]) r++;
        }
        ans+=min(l,r);
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// 1 n 