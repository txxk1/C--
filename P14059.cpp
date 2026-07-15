#include <bits/stdc++.h>

using namespace std;
int T,n,a[100005],t[3];
char ch;
void solve(){
    t[1]=0;
    t[0]=0;
    int sum=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>ch;
        a[i]=ch-'0';
        sum+=a[i];
    }
    int now=a[1];
    t[now]++;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            now=now^1;
            t[now]++;
        }
    }
    if(a[1]==a[n]) t[a[1]]--;
    //cout <<t[0]<<" "<<t[1]<<endl;
    if(sum==n){
        cout <<"Sunday"<<endl;
        return ;
    }
    if(sum==0){
        cout <<"Robin"<<endl;
        return ;
    }
    if(t[1]==1){
        cout <<"Robin"<<endl;
        return ;
    }
    t[1]=0;
    t[0]=0;
    for(int i=1;i<=n;i++){
        t[a[i]]++;
    }
    if(t[1]<=t[0]) cout <<"Sunday"<<endl;
    else cout <<"Robin"<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}