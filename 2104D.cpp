#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,s[400005],scnt,prime[400005];
int a[400005];
bool inq[10000005];
void init(){
    for(int i=2;i<=1e7;i++){
        if(inq[i]==0){
            if(scnt<=4e5) prime[++scnt]=i;
        }
        for(int j=1;j<=scnt&&i*prime[j]<=1e7;j++){
            inq[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
    s[0]=0;
    for(int i=1;i<=scnt;i++){
        s[i]=s[i-1]+prime[i];
    }
}
void solve(){
    int S=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    int ans=0;
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--){
        S+=a[i];
        
        //cout <<S<<" "<<s[n-i+1]<<endl;
        if(S<s[n-i+1]) break;
        ans++;
    }
    cout <<n-ans<<endl;
    return ;
}
signed main(){
    init();
    cin >>T;
    while(T--) solve();
    return 0;
}