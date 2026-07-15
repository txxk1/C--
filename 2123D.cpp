#include <bits/stdc++.h>
#define int long long
#define inf 1e9
using namespace std;
int T,n,k;
string a;
void solve(){
    //int ans=0;
    cin >>n>>k;
    cin >>a;
    priority_queue<int> Q;
    for(int i=0;i<n;i++){
        if(a[i]=='1') Q.push(max(i,n-i-2));
    }
    if(Q.size()<=k){
        cout <<"Alice"<<endl;
        return ;
    }
    if(n<2*k) cout <<"Alice"<<endl;
    else cout <<"Bob"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// 5+3+1+1+3