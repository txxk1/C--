#include <bits/stdc++.h>

using namespace std;
int T,n,k;
char a[105][105];
void solve(){
    cin >>n>>k;
    int t=n*n-k;
    if(t==1){
        cout <<"NO"<<endl;
        return ;
    }
    cout <<"YES"<<endl;
    int x=t/n,y=t%n;       
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]='D';
        }
    }
    if(x==0){
        for(int i=1;i<y;i++) a[1][i]='R';
        a[1][y]='L';
    }
    else{
        for(int i=1;i<=x;i++){
            for(int j=1;j<n;j++){
                a[i][j]='R';
            }
            a[i][n]='L';
        }
        for(int i=1;i<=y;i++){
            a[x+1][i]='U';
        }
    }   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout <<a[i][j];
        }
        cout <<endl;
    }
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}