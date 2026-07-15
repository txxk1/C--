#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[100005];
void solve(){
    cin >>n>>k;
    for(int i=1;i<=k;i++) a[i]=0;
    int now=1;
    if(k%2==1){
        for(int i=1;i<=k;i++){
            cout <<n<<" ";
        }
        cout <<endl;
        return ;
    }
    for(int i=31;i>=0;i--){
        if((1ll<<i)>n) continue;
        if(((n>>i)&1)==1){
            for(int j=1;j<=k;j++){
                if(j!=min(now,k)) a[j]+=(1ll<<i);
            }
            if(now<=k) now++;
        }
        else{
            for(int j=1;j<=now-1-(now-1)%2;j++){
                a[j]+=(1ll<<i);
            }
        }
    }
    for(int i=1;i<=k;i++){
        cout <<a[i]<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// 11110
// 10111
// 01001