#include <bits/stdc++.h>
using namespace std;
int T,n,cnt,t[3005];

void solve(){
    cin >>n;
    for(int i=1;i<=100;i++) t[i]=0;
    for(int i=1;i<=n;i++){
        int x;
        cin >>x;
        t[x]++;
    }
    for(int i=1;i<=100;i++){
        if(t[i]>1){
            cout <<"YES"<<endl;
            return ;
        }
    }
    cout <<"NO"<<endl;
    return ;
}
int main(){
	cin >>T;
    while(T--) solve();
	return 0;
}
// 10 9 8 11 7 6
// 2 3 9 5 6
// 2 3 4 11 5 6