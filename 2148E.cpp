#include <bits/stdc++.h>
#define inf 1e16
#define int long long
using namespace std;
int T,n,k,a[200005];

void solve(){
    map<int,int> f;
    map<int,int> s;
    int ans=0;
    cin >>n>>k;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        s[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(s[a[i]]%k!=0){
            cout <<0<<endl;
            return ;
        }
    }
    int l=1,r=1;
    f[a[1]]++;
    while(l<=n){
        while(f[a[r]]<=s[a[r]]/k&&r<=n){
            r++;
            f[a[r]]++;
        }
        ans+=r-l;
        f[a[l]]--;
        l++;
    }
    cout <<ans<<endl;
    return ;
}

signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}