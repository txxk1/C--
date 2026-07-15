#include <bits/stdc++.h>

using namespace std;
int T,n,m;
struct node{
    int a,b;
}e[200005];
void solve(){
    cin >>n>>m;
    for(int i=1;i<=n;i++) cin >>e[i].a>>e[i].b;
    int sum=0;
    e[0].a=0;
    e[0].b=0;
    for(int i=1;i<=n;i++){
        int x=e[i].a-e[i-1].a;
        int y=e[i].b+2-e[i-1].b;
        if(x%2!=y%2) sum++;
    }
    cout <<m-sum<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}