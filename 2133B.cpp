#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,cnt,t[200005];

void solve(){
    int ans=0;
    cin >>n;
    //for(int i=1;i<=100;i++) t[i]=0;
    for(int i=1;i<=n;i++){
        cin >>t[i];
    }
    sort(t+1,t+1+n);
    for(int i=n;i>=1;i-=2){
        ans+=t[i];
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
	cin >>T;
    while(T--) solve();
	return 0;
}