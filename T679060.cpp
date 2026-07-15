#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[1000005];
void solve(){
    cin >>n;    
    memset(a,0,sizeof(a));
    a[1]=1;
    a[2]=0;
    a[3]=2;
    if(n==1){
        cout <<"impossible"<<endl;
        return ;
    }
    else if(n<=3){
        for(int i=1;i<=n;i++){
            cout <<a[i]<<" ";
        }
        cout <<endl;
        return ;
    }
    else{
        if(n%4==0){
            cout <<"impossible"<<endl;
            return ;
        }
        for(int i=4;i<=n;i++){
            a[i]=i-1;
        }
        for(int i=1;i<=n/4;i++){
            swap(a[i*4],a[i*4+1]);
        }
        for(int i=1;i<=n;i++){
            cout <<a[i]<<" ";
        }
    }

    return ;
}
signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}