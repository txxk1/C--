#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,q,x,ans;
struct node{
    int l,r;
}lin[300005];
bool cmp(node a,node b){
    if(a.l==b.l) return a.r>b.r;
    return a.l<b.l;
}
void solve(){
    cin >>n>>q;
    for(int i=1;i<=q;i++){
        cin >>lin[i].l>>lin[i].r;
    }
    sort(lin+1,lin+1+q,cmp);
    int now=lin[1].r,qwq;
    cout <<"? "<<lin[1].l<<" "<<lin[1].r<<endl;
    cin >>x;
    ans=x;
    if(x==0) now=lin[1].r;
    for(int i=2;i<=q;i++){
        if(lin[i].r<=lin[i-1].r) continue;
        if(lin[i].r<=now) continue;
        cout <<"? "<<lin[i].l<<" "<<lin[i].r<<endl;
        cin >>x;
        //ans=max(ans,x);
        if(x==0) now=lin[i].r;
        else{
            qwq=i;
            ans=max(ans,x);
            break;
        }
    }
    
    cout <<"! "<<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}