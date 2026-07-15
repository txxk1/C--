#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200005],b[200005],t[200005];
void solve(){
    cin >>n;
    int ans=-1,flag=0;
    a[n+1]=0;
    b[n+1]=0;
    for(int i=1;i<=n;i++) cin >>a[i],t[i]=0;
    for(int i=1;i<=n;i++) cin >>b[i];
    if(a[n]==b[n]){
        cout <<n<<endl;
        return;
    }
    for(int i=n-1;i>=1;i--){
        
        if(a[i]==b[i]){
            ans=i;
            break;
        }
        if(a[i]==a[i+1]){
            ans=i;
            break;
        }
        if(b[i]==b[i+1]){
            ans=i;
            break;
        }
        if(t[a[i]]!=0||t[b[i]]!=0){
            ans=i;
            break;
        }
        t[a[i+1]]=1;
        t[b[i+1]]=1;
    }
    if(ans==-1) cout <<0<<endl;
    else cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}