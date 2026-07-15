#include <bits/stdc++.h>
 
using namespace std;
int T,x,y,z;
void solve(){
    cin >>x>>y>>z;
    int a=x&y;
    int b=x&z;
    int c=y&z;
    if( (a&z)!=a ){
        cout <<"NO"<<endl;
        return ;
    }
    if( (b&y)!=b ){
        cout <<"NO"<<endl;
        return ;
    }
    if( (c&x)!=c ){
        cout <<"NO"<<endl;
        return ;
    }
    cout <<"YES"<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}