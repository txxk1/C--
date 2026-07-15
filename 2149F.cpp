#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,h,d;
bool check(int x){
    //if(x==0) return d*(d+1)/2<=h;
    int n=d%(x+1),m=x+1-n;
    int asd=d/(x+1);
    int sum=n*((asd+2ll)*(asd+1ll)/2)+m*((asd+1ll)*asd/2);
    return sum<h+x;
}
// d divide x
// 
// n*(asd+1)+m*asd
// -d
// ffff ttttt
void solve(){
    cin >>h>>d;
    int l=0,r=d-1;
    while(l<r){
        int mid=(l+r)/2;
        if(!check(mid)) l=mid+1;
        else r=mid-1;
    }
    int qwq=0;
    for(int i=l+2;i>=max(0ll,l-2);i--){
        if(check(i)){
            qwq=i;
        }
    }
    cout <<d+qwq<<endl;
    return ;
}
// 7 2
// 2 2 3
// 3+3+6=12 10+2
// h+m+n
// m=n/k n%k
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
//44 12 13
// 22 6