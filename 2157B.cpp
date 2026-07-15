#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,t[105];
void solve(){
    int ans=0;
    cin >>n;
    for(int i=0;i<=n;i++) t[i]=0;
    for(int i=1;i<=n;i++){
        int x;
        cin >>x;
        t[x]++;
    }
    for(int i=0;i<=n;i++){
        if(t[i]==0) continue;
        if(t[i]!=i){
            if(t[i]>i) ans+=t[i]-i;
            else ans+=t[i];
        }
        
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}