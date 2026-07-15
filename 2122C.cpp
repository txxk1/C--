#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
struct node{
    int x,y,id;
}p[200005];
bool cmp(node a,node b){
    return a.x<b.x;
}
void solve(){
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>p[i].x>>p[i].y;
        p[i].id=i;
    }
    sort(p+1,p+1+n,cmp);

    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
/*

*/ 