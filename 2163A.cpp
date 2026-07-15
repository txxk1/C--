#include <bits/stdc++.h>

using namespace std;
int T,n,m,a[200005];

void solve(){
	cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<n;i+=2){
        if(a[i]!=a[i+1]){
            cout <<"NO"<<endl;
            return ;
        }
    }
    cout <<"YES"<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}