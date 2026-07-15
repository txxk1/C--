#include <bits/stdc++.h>
#define int long long
using namespace std;

int T,k,f[1005],p[105],qwq,s[1005];
void init(){
    p[0]=1ll;
    for(int i=1;i<=15;i++) p[i]=p[i-1]*10ll;
    f[1]=9;
    s[1]=45;
    int now=9;
    for(int i=2;now<=1e16;i=i+1ll){
        f[i]=now+(p[i]-p[i-1])*i;
        s[i]=p[i]/2ll*9ll;
        now=f[i];
        //cout <<i<<" "<<f[i]<<" "<<s[i]<<endl;
        qwq=i;
    }
}
int cost(int x,int qwq){
    int lin[105];
    int cf=x,cnt=0,sum=0;
    while(x){
        lin[++cnt]=x%10;
        x=x/10;
    }
    for(int i=cnt;i>=cnt-qwq+1;i--) sum+=lin[i];
    return sum;
}
void solve(){
    cin >>k;
    int bite=0;
    for(int i=1;i<=15;i++){
        //cout <<i<<" "<<p[i]<<" "<<k<<endl;
        if(f[i]>k) break;
        else bite=i;
    }
    int ans=s[bite],res=k-f[bite],lg=bite+1;
    int x=res/lg,qwq=res%lg;
    int sum=0ll,cnt=0ll;
    //x+=p[bite+1];
    for(int i=bite+1;i>=0;i--){
        //cnt=cnt*10ll;
        cnt=x/p[i],res=x%p[i];
        if(i==bite) sum+=cnt*(cnt+1ll)/2ll*p[i-1]+(res+1ll)*(cnt%10ll+1ll);
        else if(i==0) sum+=(cnt/10ll)*45ll+(cnt%10ll-1ll)*(cnt%10ll)/2ll+(res+1ll)*(cnt%10ll);
        else sum+=(cnt/10ll)*45ll+(cnt%10ll-1ll)*(cnt%10ll)/2ll*p[i-1]+(res+1ll)*(cnt%10ll);
    
    }
    sum+=cost(p[bite+1]+x,qwq);
    cout <<ans+sum<<endl;
    return ;
}
//  20305
//  1 cnt=1 res=305
//  2 cnt=20
//  3 cnt=203 20*45+ 
//  4 cnt=2030 203*45
//              n   4 3 2 1
//              pn
// 10000 - xxxxx
signed main(){
    init();
    cin >>T;
    while(T--) solve();
    return 0;
}