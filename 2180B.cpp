#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
string x;
void solve(){
    string ans="",pre="{";
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>x;
        string a=x+ans;
        string b=ans+x;
        if(a<b) ans=a;
        else ans=b;
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// aaaab