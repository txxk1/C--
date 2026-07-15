#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,l[200005],r[200005],d[200005],ans[200005];
void solve(){
    cin >>n;
    for(int i=1;i<=n;i++) cin >>d[i];
    for(int i=1;i<=n;i++){
        cin >>l[i]>>r[i];
    }
    int L=0,R=0;
    for(int i=1;i<=n;i++){
        int flag=0;
        if(d[i]==1) L++,R++;
        if(d[i]==-1) R++;
        if(L>r[i]||R<l[i]){
            cout <<-1<<endl;
            return ;
        }
        if(d[i]==-1){
            if(L>l[i]) ans[i]=0;
            else ans[i]=1; 
        }
        else ans[i]=d[i];
        L=max(L,l[i]);
        R=min(R,r[i]);
    }
    for(int i=1;i<=n;i++){
        cout <<ans[i]<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
//
// k 进制进位多少次