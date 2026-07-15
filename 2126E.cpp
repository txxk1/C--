#include <bits/stdc++.h>
#define int long long
using namespace std;

int T,n,a[200005],b[200005];
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
void solve(){
    cin >>n;
    int now=0;
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=n;i++) cin >>b[i];
    for(int i=2;i<=n;i++){
        if(a[i-1]%a[i]!=0){
            cout <<"NO"<<endl;
            return ;
        }
    }
    for(int i=n;i>1;i--){
        if(b[i]%b[i-1]!=0){
            cout <<"NO"<<endl;
            return ;
        }
    }
    if(n==1){
        if(a[1]!=b[1]) cout <<"NO"<<endl;
        else cout <<"YES"<<endl;
        return ;
    }
    now=b[1];
    if(b[1]!=a[n]){
        cout <<"NO"<<endl;
        return ;
    }
    for(int i=1;i<n;i++){
        int qwq=gcd(a[i],b[i+1]);
        if(qwq!=now){
            cout <<"NO"<<endl;
            return ;
        }
    }
    cout <<"YES"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}