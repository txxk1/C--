#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,a[200005];
void solve(){
    cin >>n;
    if(n==1){
        cout <<1<<endl;
    }
    else if(n==2){
        cout <<9<<endl;
    }
    else if(n==3){
        cout <<29<<endl;
    }
    else if(n==4){
        cout <<56<<endl;
    }
    else{
        cout <<5*(n*(n-1)-1)<<endl;
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}