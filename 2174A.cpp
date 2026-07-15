#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[105],t[1005];
void solve(){
    int sum=0;
    cin >>n;
    for(int i=1;i<=1000;i++) t[i]=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        if(t[a[i]]==0){
            t[a[i]]++;
            sum++;
        }
    }
    for(int i=n+1;i<=1000;i++){
        if(t[sum]==0){
            t[sum]=1;
            sum++;
        }
        else break;
    }
    cout <<sum<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}