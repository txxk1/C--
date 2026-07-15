#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200005],s1[200005],s2[200005],v[200005],fa[200005];
struct node{
    int x,y;
}e[200005];
void solve(){
    cin >>n;
    int cnt=0;
    s1[0]=1e9;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        s1[i]=min(s1[i-1],a[i]);
    }
    s2[n+1]=-1;
    for(int i=n;i>=1;i--) s2[i]=max(s2[i+1],a[i]);
    for(int i=1;i<n;i++){
        if(s1[i]>s2[i+1]){
            cout <<"NO"<<endl;
            return ;
        }
        e[++cnt]
    }
    cout <<"YES"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}