#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
bool check1(int x){
    return x*(n-x)+(n-x-1ll)*(n-x)/2>=m;
}
bool check2(int x){
    if(x<=0) return true;
    int a=n%(x),b=x-a;
    int asd=n/(x);
    int sum=a*((asd)*(asd+1ll)/2)+b*((asd-1ll)*asd/2);
    return sum>m;
}
void solve(){
    cin >>n>>m;
    int l=0,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(check1(mid)) l=mid+1;
        else r=mid-1;
    }
    int minn,maxn;
    for(int i=l+2;i>=l-2;i--){
        if(check1(i)){
            maxn=i;
            break;
        }
    }
    l=1;
    r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(check2(mid)) l=mid+1;
        else r=mid-1;
    }
    for(int i=l+2;i>=l-2;i--){
        if(check2(i)){
            minn=i;
            break;
        }
    }
    cout <<maxn<<" "<<minn+1<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}