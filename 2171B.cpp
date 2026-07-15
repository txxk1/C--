#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int T,n,a[200005];
void print(){
    cout <<abs(a[1]-a[n])<<endl;
    for(int i=1;i<=n;i++){
        if(a[i]==-1) cout <<0<<" ";
        else cout <<a[i]<<" ";
    }
    cout <<endl;
    return ;
}
void solve(){
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i];
    int f1=(a[1]==-1),fn=(a[n]==-1);
    if(a[1]!=-1&&a[n]!=-1){
        print();
    }
    else{
        if(a[1]==-1&&a[n]==-1){
            a[1]=0;
            a[n]=0;
            print();
        }
        else{
            if(a[1]==-1){
                a[1]=a[n];
                print();
            }
            if(a[n]==-1){
                a[n]=a[1];
                print();
            }
        }
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}