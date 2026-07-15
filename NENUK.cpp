#include <bits/stdc++.h>
using namespace std;
int T,n,k;
char a[100005];
void print(){
    for(int i=1;i<=n;i++){
        if(a[i]=='?') cout <<0;
        else cout <<a[i];
    }
    return ;
}
void solve(){
    cin >>n;
    cin >>a+1;
    int cnt=0;
    if(a[1]=='?') cnt++;
    if(a[n]=='?') cnt++;
    if(cnt==0){
        if(a[1]!=a[n]){
            cout <<-1<<endl;
            return ;
        }
        else print();
    }
    else if(cnt==2){
        a[1]='0';
        a[n]='0';
        print();
    }
    else{
        if(a[1]=='?') a[1]=a[n];
        else a[n]=a[1];
        print();
    }
    cout <<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}