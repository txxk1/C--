#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n,ax,ay,bx,by,nowx,nowy,ans,flag;
char a[100005];
void add(ll x,ll px,ll py){
    ll l=0ll,r=8000000000ll;
    while(l<r){
        // fff ttt
        ll mid=(l+r)/2ll;
        ll qwq=abs(ax+px-bx+nowx*mid)+abs(ay+py-by+nowy*mid);
        if(qwq<=mid*n+x) r=mid-1;
        else l=mid+1;
    }
    for(ll i=max(0ll,l-2ll);i<=min(8000000000ll,l+2ll);i++){
        ll qwq=abs(ax+px-bx+nowx*i)+abs(ay+py-by+nowy*i);
        if(qwq<=i*n+x) ans=min(ans,i*n+x);
    }
}
void solve(){
    cin >>ax>>ay>>bx>>by;
    cin >>n;
    cin >>a;
    nowx=0ll,nowy=0ll,ans=(1ll<<62),flag=0;
    ll qwq=abs(ax-bx)+abs(ay-by);
    for(ll i=0;i<n;i++){
        if(a[i]=='U')nowy++;
        if(a[i]=='D')nowy--;
        if(a[i]=='L')nowx--;
        if(a[i]=='R')nowx++;
        ll res=abs(ax+nowx-bx)+abs(ay+nowy-by);
        if(res<qwq) flag=1;
        qwq=res;
    }
    if(ax==bx&&ay==by){
        cout <<0<<endl;
        return ;
}
    if(flag==0){
        cout <<-1<<endl;
        return ;
    }
    ll px=0ll,py=0ll;
    for(int i=0;i<n;i++){
        if(a[i]=='U')py++;
        if(a[i]=='D')py--;
        if(a[i]=='L')px--;
        if(a[i]=='R')px++;
        add(i+1,px,py);
    }
    cout <<ans<<endl;
    return ;
}
int main(){
    //freopen("007.in","r",stdin);
    solve();
    return 0;
}