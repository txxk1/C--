#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,p[200005],d[200005],t[200005];
void solve(){
    cin >>n;
    for(int i=1;i<=n;i++) cin >>p[i];
    for(int i=1;i<=n;i++) cin >>d[i],t[i]=0;
    int ans=0;
    queue<int> Q;
    for(int i=1;i<=n;i++){
        if(t[d[i]]==0) Q.push(d[i]),ans++;
        while(!Q.empty()){
            int qwq=Q.front();
            t[qwq]=1;
            Q.pop();
            if(t[p[qwq]]==0){
                t[p[qwq]]=1;
                Q.push(p[qwq]);
                ans++;
            }
        }
        cout <<ans<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}