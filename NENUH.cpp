#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int T,n,k;
int a[10005],t[10005];
void solve(){
    int ans=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    sort(a+1,a+1+n);
    int now=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=now) now++;
        else now--;
    }
    cout <<now<<endl;
    return ;
}
signed main(){
    solve();
    return 0;
}