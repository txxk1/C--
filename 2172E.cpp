#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,s[10][125],a[10],now,v[20],cnt;
void dfs(int x){
    if(x==now+1){
        cnt++;
        for(int k=1;k<=now;k++){
            s[k][cnt]=a[k];
        }
    }
    for(int i=1;i<=now;i++){
        if(v[i]==0){
            v[i]=1;
            a[x]=i;
            dfs(x+1);
            v[i]=0;
        }
    }
}
void solve(){
    cnt=0;
    cin >>n>>i>>j;
    if(n==12) now=2;
    if(n==123) now=3;
    if(n==1234) now=4;
    dfs(1);
    int cnt1=0,cnt2=0;
    for(int k=1;k<=now;k++){
        if(s[k][i]==s[k][j]) cnt1++;
        else cnt2++;
    }
    cout <<cnt1<<"A"<<cnt2<<"B"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
//  3 -> x=1 +1
//  9 -> x=2 +6
//