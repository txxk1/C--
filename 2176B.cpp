#include <bits/stdc++.h>
using namespace std;
int T,n,t[200005];
char a[200005];
void solve(){
    int ans=0,flag=0,sum=0;
    cin >>n;
    cin >>a+1;
    int pre=0,suf=0;
    int now=1;
    while(a[now]=='0') now++;
    pre=now-1;
    now=n;
    while(a[now]=='0') now--;
    suf=n-now;
    for(int i=1;i<=n;i++){
        if(a[i]=='1'){
            ans=max(ans,sum);
            flag=1;
            sum=0;
        }
        else{
            flag=0;
            sum++;
        }
    }
    cout <<max(ans,pre+suf)<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}