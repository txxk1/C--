#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200005],t[4],b[200005];
void solve(){
    int sum=0,cnt=0;
    t[0]=t[1]=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        if(a[i]%2==0) sum+=a[i],t[0]++;
        else t[1]++,b[++cnt]=a[i];
    }
    if(t[1]==0){
        cout <<0<<endl;
        return ;
    }
    sort(b+1,b+1+cnt);
    for(int i=cnt;i>=cnt/2+1;i--){
        sum+=b[i];
    }
    //cout <<cnt/2+1-cnt%2<<endl;
    cout <<sum<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}