#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y,a[100005],t[400005];
queue<pair<int,int> > Q;
void solve(){
    cin >>x>>y;
    int ans=1;
    Q.push(make_pair(x,y));
    while(!Q.empty()){
        int x=Q.front().first,y=Q.front().second;
        Q.pop();
        if(y>=x*2){
            ans++;
            Q.push(make_pair(x,(x+y)/2));
            Q.push(make_pair((x+y)/2+1,y));
        }
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}