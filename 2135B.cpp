#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y,pos,neg;
void solve(){
    cin >>n;
    pos=-4e9;
    neg=-4e9;
    for(int i=1;i<=n;i++){
        cin >>x>>y;
        pos=max(pos,x+y);
        neg=max(neg,y-x);
    }
    int now;
    cout <<"? U 1000000000"<<endl;
    cin >>now;
    cout <<"? U 1000000000"<<endl;
    cin >>now;
    cout <<"? R 1000000000"<<endl;
    cin >>now;
    cout <<"? R 1000000000"<<endl;
    cin >>now;
    int qwq=now;
    qwq=qwq+pos-4e9;
    cout <<"? L 1000000000"<<endl;
    cin >>now;
    cout <<"? L 1000000000"<<endl;
    cin >>now;
    cout <<"? L 1000000000"<<endl;
    cin >>now;
    cout <<"? L 1000000000"<<endl;
    cin >>now;
    now=now+neg-4e9;
    cout <<"! "<<(qwq-now)/2<<" "<<(qwq+now)/2<<endl;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}