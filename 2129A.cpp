#include <bits/stdc++.h>
using namespace std;
int T,n,cnt,ans[3005];
struct node{
    int l,r,id;
}e[3003];
bool cmp(node x,node y){
    if(x.l!=y.l) return x.l<y.l;
    return x.r>y.r;
}
void solve(){
    cnt=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>e[i].l>>e[i].r;
        e[i].id=i;
    }
    sort(e+1,e+1+n,cmp);
    int l=1,r;
    while(l<=n){
        int now=l+1;
        while(e[now].r<=e[l].r) now++;
        ans[++cnt]=e[l].id;
        l=now;
    }
    cout <<cnt<<endl;
    for(int i=1;i<=cnt;i++){
        cout <<ans[i]<<" ";
    }
    cout <<endl;
    return ;
}
int main(){
	cin >>T;
    while(T--) solve();
	return 0;
}
// 10 9 8 11 7 6
// 2 3 9 5 6
// 2 3 4 11 5 6