#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,a,b,n;
void solve(){
    cin >>a>>b>>n;
    if(b*n<=a){
        cout <<1<<endl;
        return ;
    }
    if(b>=a){
        cout <<1<<endl;
        return ;
    }
    int x=a/b;
    cout <<2<<endl;
    return ;
}
// b*n>a
// b>a/n
//  x  a/x==b
// a/n
// a/(n-1)
// a/x = b
// a/(x+1) <b
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}