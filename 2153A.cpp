#include <bits/stdc++.h>
 
using namespace std;
int T,n,t[105];
void solve(){
    int ans=0;
    cin >>n;
    for(int i=1;i<=100;i++) t[i]=0;
    for(int i=1;i<=n;i++){
        int x;
        cin >>x;
        if(t[x]==0){
            ans++;
            t[x]++;
        }
    }
    cout <<ans<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}