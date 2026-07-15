#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y,k;
int check(int mid,int x,int y){
    int w=mid,t=x;
    while(t--){
        w-=w/y;
    }
    return w>=k;
}
void solve(){
    cin >>x>>y>>k;
    int N=1e12;
    int now=x;
    while(now--){
        N-=N/y;
        //cout <<N<<endl;
    }
    if(k>N){
        cout <<-1<<endl;
        return ;
    } 
    int l=1,r=1e12;
    while(l<r){
        int mid=(l+r)/2;
        if(!check(mid,x,y)) l=mid+1;
        else r=mid-1;
    }
    int qwq;
    for(int i=l+2;i>=l-2;i--){
        if(check(i,x,y)) qwq=i;
    }
    cout <<qwq<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}