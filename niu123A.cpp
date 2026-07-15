#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a,b;
char cha,chb;
signed main(){
    cin >>a>>cha;
    cin >>b>>chb;
    if(a>b){
        cout <<"YES"<<endl;
    }
    if(a==b){
        if(cha-'A'>chb-'B') cout <<"YES"<<endl;
        else cout <<"NO"<<endl;
    }
    if(a<b){
        cout <<"NO"<<endl;
    }
    return 0;
}