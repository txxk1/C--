#include <bits/stdc++.h>
#define int long long
using namespace std;
int check(int x){
    int qwq=0,sum=0,ans=x;
    while(x){
        qwq=x%10;
        sum+=qwq*qwq*qwq;
        x=x/10;
    }
    return ans==sum;
}
void solve(){
    for(int i=0;i<=1000;i++){
        if(check(i)==1) cout <<i<<" ";
    }
    return ;
}

signed main(){
    solve();
    return 0;
}