#include <bits/stdc++.h>
using namespace std;
int T,n,a[105],t[105];
void solve(){
    cin >>n;
    memset(t,0,sizeof(t));
    for(int i=1;i<=n;i++){
        cin >>a[i];
        t[a[i]]++;
    }
    sort(t+1,t+1+n);
    int now=0,ans=-1,nowid=105,x=0;
    for(int i=n;i>=1;x++){
        if(nowid>t[i]){

            nowid=t[i];
            while(t[i]==nowid&&i>=1){
                now++;
                i--;
            }
            ans=max(ans,now*nowid);
        }
    }
    cout <<ans<<endl;
}
int main(){
    cin >>T;
    while(T--){
        solve();
    }
    return 0;
}