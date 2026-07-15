#include <bits/stdc++.h>

using namespace std;
int T,n,t[30];
char ch;
void solve(){
    cin >>n;
    for(int i=1;i<=26;i++) t[i]=0;
    for(int i=1;i<=n;i++){
        cin >>ch;
        t[ch-'a'+1]++;
    }
    cout <<n-t[ch-'a'+1]<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}