#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,a,b,tla,tlb,tra,trb,ans;
char s[300005];
void solve(){
    cin >>n>>a>>b;
    cin >>s+1;
    int l=1,r=1;
    for(int i=1;i<=n;i++){
        while(tla<a&&l<=n){
            if(s[l]=='a') tla++;
            if(s[l]=='b') tlb++;
            l++;
        }
        while(tra<a&&r<=n){
            if(s[r]=='a') tra++;
            if(s[r]=='b') trb++;
            r++;
        }
        while(trb<b&&r<=n){
            if(s[r]=='a') tra++;
            if(s[r]=='b') trb++;
            r++;
        }
        ans+=r-l;
        if(s[i]=='a') tra--,tla--;
        if(s[i]=='b') trb--,tlb--;
    }
    cout <<ans;
    return ;
}
signed main(){
    solve();
    return 0;
}