#include <bits/stdc++.h>

using namespace std;
int T,n,k;
int a[200005],t[2];
void solve(){
    t[0]=0;
    t[1]=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        t[a[i]%2]++;
    }
    if(t[0]>0&&t[1]>0) sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) cout <<a[i]<<" ";
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}