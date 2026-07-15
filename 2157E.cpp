#include <bits/stdc++.h>
#define int long long
#define inf 1e9
using namespace std;
int T,n,k,a[200005],t[800005];

void solve(){
    int ans=0,cnt=0,flag=0,now=0;
    cin >>n>>k;
    for(int i=1;i<=n;i++) cin >>a[i],t[a[i]]++;
    for(int i=1;i<=n*4;i++){
        if(flag==0){
            if(t[i]<=k) continue;
            flag=1;
            cnt+=t[i]-1;
            now++;
        }
        else{
            if(t[i]==0){
                if(cnt<=k){
                    flag=0;
                    now=0;
                    cnt=0;
                    continue;
                }
                now++;
                cnt-=1;
            }
            else{
                cnt+=t[i]-1;
                now++;
            }
        }
        ans=max(ans,now);
    }
    for(int i=1;i<=n;i++) t[a[i]]=0;
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// 5+3+1+1+3