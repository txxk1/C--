#include <bits/stdc++.h>

using namespace std;
int T,n,k;
int a[35],t[35];
void solve(){
    cin >>n;
    for(int i=1;i<=26;i++) a[i]=0,t[i]=0;
    for(int i=1;i<=n;i++){
        char ch;
        cin >>ch;
        a[ch-'a'+1]++;
    }
    for(int i=1;i<=n;i++){
        char ch;
        cin >>ch;
        t[ch-'a'+1]++;
    }
    for(int i=1;i<=26;i++){
        if(a[i]!=t[i]){
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