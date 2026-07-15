#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,k,a[200005],t[200005],ans[200005],s[200005];
void solve(){
    cin >>n;
    for(int i=0;i<=n;i++) t[i]=0,s[i]=0;
    for(int i=1;i<=n;i++) cin >>a[i],t[a[i]]++;
    sort(a+1,a+1+n);
    int qwq;
    for(int i=0;i<=n;i++){
        if(t[i]==0){
            qwq=i;
            break;
        }
    }
    for(int i=0;i<qwq;i++){
        s[t[i]]++;
    }
    int now=qwq-1,cnt=1;
    for(int i=n;i>=n-qwq+1;i--){
        ans[i]=n-i+1;
    }
    for(int i=1;i<=n-qwq;i++){
        cnt+=s[i];
        ans[i]=cnt;
    }
    ans[0]=1;
    for(int i=0;i<=n;i++){
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