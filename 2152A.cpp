#include <bits/stdc++.h>

using namespace std;
int T,n,k,a[105];
void solve(){
    int ans=0;
    cin >>n;
    for(int i=1;i<=100;i++) a[i]=0;
    for(int i=1;i<=n;i++){
        cin >>k;
        if(a[k]==0) a[k]++,ans++;
    }
    cout <<ans*2-1<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}