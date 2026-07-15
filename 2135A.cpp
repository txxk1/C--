#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200005],f[200005];
vector<int> t[200005];
void solve(){
    int ans=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        t[a[i]].push_back(i);
        int x=t[a[i]].size();
        f[i]=max(f[i],f[i-1]);
        if(x>=a[i]){
            f[i]=max(f[i],f[t[a[i]][x-a[i]]-1]+a[i]);
        }
    }
    cout <<f[n]<<endl;
    for(int i=1;i<=n;i++){
        t[i].clear();
        f[i]=0;
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}