#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y;
void solve(){
    int sum=0;
    cin >>n>>x>>y;
    x=abs(x);
    y=abs(y);
    for(int i=1;i<=n;i++){
        char ch;
        cin >>ch;
        if(ch=='8') sum++;
    }
    int xx=max(x,y);
    int yy=min(x,y);
    if(n>=xx&&n+sum>=xx+yy) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}