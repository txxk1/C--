#include <bits/stdc++.h>

using namespace std;
int T,n,k,a[200005],sum[200005],t[200005];
void solve(){
    cin >>n>>k;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        t[a[i]/4]++;
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0){
                if(j>a[i]/4) sum[j]++;
                if(a[i]/j!=j&&a[i]/j>a[i]/4) sum[a[i]/j]++;
            }
        }
    }
    t[n+1]=0;
    for(int i=n;i>=1;i--){
        t[i]+=t[i+1];
        if(sum[i]+t[i]>=n-k){
            cout <<i<<endl;
            break;
        }
        //cout <<sum[i]<<" "<<t[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        t[i]=0;
        sum[i]=0;
    }
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}