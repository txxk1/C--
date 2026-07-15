#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,s[300005];
char a[105];
char c[19]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
void solve(){
    cin >>a;
    cout <<"#";
    for(int i=1;i<7;i++){
        for(int j=0;j<16;j++){
            if(c[j]==a[i]){
                cout <<c[15-j];
            }
        }
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
}