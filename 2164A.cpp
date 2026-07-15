#include <bits/stdc++.h>

using namespace std;
int T,n,x,y,now;
void solve(){
    cin >>n;
    x=-2e9;
    y=2e9;
    for(int i=1;i<=n;i++){
        int qwq;
        cin >>qwq;
        x=max(x,qwq);
        y=min(y,qwq);
    }
    cin >>now;
    if(now>=y&&now<=x) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}