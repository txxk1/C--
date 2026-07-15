#include <bits/stdc++.h>
using namespace std;
int T,n,a[105],t[105];
void solve(){
    int ans=0;
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i],t[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i]) t[j]=1;
        }
    }
    for(int i=1;i<=n;i++) ans+=(t[i]==1);
    cout <<ans<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}