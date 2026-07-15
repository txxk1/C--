#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105];
void solve(){
    cin >>n>>m;
    for(int i=1;i<=n*m;i++){
        cin >>a[i];
    }
    int x=a[1],rk;
    sort(a+1,a+1+n*m);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            rk=n*m-i+1;
        }
    }
    int qwq=rk/(2*n),now=rk%(2*n);
    int ans1=qwq*2+(now>n)+(now>0);
    int ans2;
    //int ans2=n-abs(now-n)+1;
    if(now==0) ans2=1;
    else if(now<=n) ans2=now;
    else ans2=n*2-now+1;
    // now=5 n=4 ans2=3
    cout <<ans1<<" "<<ans2;
    return ;
}

signed main(){
    solve();
    return 0;
}