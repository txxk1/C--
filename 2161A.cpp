#include <bits/stdc++.h>

using namespace std;
int T,r,x,d,n,qwq;
char ch;
void solve(){
    int ans=0;
    cin >>r>>x>>d>>n;
    for(int i=1;i<=n;i++){
        cin >>ch;
        if(ch=='1'){
            ans++;
            r-=d;
        }
        else{
            if(r<x) ans++;

        }
    }
    cout <<ans<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}