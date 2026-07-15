#include <bits/stdc++.h>
#define int long long
using namespace std;
int t[10];
string a;
void solve(){
    cin >>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            t[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=t[i];j++){
            cout <<i;
        }
    }
    return ;
}

signed main(){
    solve();
    return 0;
}