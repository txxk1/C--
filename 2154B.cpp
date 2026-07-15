#include <bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;
int T,n,k;
int a[200005],b[200005];
void solve(){
    int ans=0,sum=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    b[1]=a[1];
    for(int i=2;i<=n;i++){
        sum=max(sum,b[i-1]);
        b[i]=a[i];
        if(i%2==0){
            if(a[i]<=a[i-1]){
                a[i]=sum;
                b[i]=sum;
                if(sum==a[i-1]) ans++;
            }
        }
        else{
            if(a[i]>=max(sum,a[i-1])){
                ans+=a[i]-max(sum,a[i-1])+1;
                a[i]=max(sum,a[i-1])-1;
            }
        }
    }
    cout <<ans<<endl;
    return ;
}
// 8+5
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}