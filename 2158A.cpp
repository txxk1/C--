#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200005],x,y;
void solve(){
    cin >>n;
    cin >>x>>y;
    cout <<min(n,y+x/2)<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
//
// k 进制进位多少次