#include <bits/stdc++.h>
using namespace std;
int gt(int x){
    if(x==0) return 1;
    if(x==1) return 10;
    if(x==2) return 5;
    if(x==3) return 10;
    if(x==4) return 5;
    if(x==5) return 2;
    if(x==6) return 5;
    if(x==7) return 10;
    if(x==8) return 5;
    if(x==9) return 10;
    else return 10;
}
void solve(){
    int q;
    cin >>q;
    cout <<gt(q%10)<<endl;
    return ;
}
int main(){
    solve();
    return 0;
}