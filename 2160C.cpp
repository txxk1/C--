#include <bits/stdc++.h>
#define int long long 
using namespace std;
int x,T,t[203],a[35],cnt;
void solve(){
    cnt=0;
    cin >>x;
    for(int i=0;i<=30;i++){
        if((x&(1<<i))==0) t[i]=0;
        else{
            a[++cnt]=i;
            t[i]=1;
        }
    }
    if(cnt%2==1){
        cout <<"NO"<<endl;
        return ;
    }
    int l=0,r=0;
    for(int i=29;i>=0;i--){
        if(t[i]==1) break;
        else r++;
    }
    for(int i=0;i<30;i++){
        if(t[i]==1) break;
        else l++;
    }
    int qwq=a[1]+a[cnt];
    for(int i=2;i<=cnt;i++){
        if(a[i]+a[cnt-i+1]!=qwq){
            cout <<"NO"<<endl;
            return ;
        }
    }
    cout <<"YES"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}