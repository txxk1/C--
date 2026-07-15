#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,l,r,a[200005];
void debug(){ cout <<"BUG"<<endl; }
int cost(int len1,int len2,int l,int r){
    if(len2<l||len1>r) return 0;
    return min(r,len2)-max(l,len1)+1;
}
// min(r+i,R)-max(l+i,L+1)
void solve(){
    int ans=0;
    map<int,int> f,g;
    cin >>n>>k>>l>>r;
    for(int i=1;i<=n;i++) cin >>a[i];
    int L=1,R=1;
    a[n+1]=0;
    int cntL=0,cntR=0;
    for(int i=1;i<=n;i++){
        while(L<=n&&cntL<k){
            if(f[a[L]]==0) cntL++;
            f[a[L]]++;
            L++;
        }
        while(R<=n&&cntR<=k){
            if(g[a[R]]==0){
                if(cntR==k) break;
                cntR++;
            }
            g[a[R]]++;
            R++;
        }
        int len1=L-i;
        int len2=R-i;
        if(cntL==k) ans+=cost(len1,len2,l,r);
        if(f[a[i]]==1) cntL--;
        if(g[a[i]]==1) cntR--;
        f[a[i]]--;
        g[a[i]]--;
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}