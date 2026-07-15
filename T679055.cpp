#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[105],s[105],m;
void solve(){
    int sum=0;
    cin >>n>>k;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        sum+=(a[i])/k;
        s[i]=a[i]-(a[i]/k)*k;
    }
    cin >>m;
    sort(s+1,s+1+n);
    for(int i=n;i>=1;i--){
        if(k-s[i]<=m){
            m-=k-s[i];
            sum++;
            //s[i]=0;
        }
        else{
            cout <<sum<<endl;
            return ;
        }
    }
    cout <<sum+m/k<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}