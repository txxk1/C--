#include <bits/stdc++.h>

using namespace std;
int T,n,m,a[105],b[105],t[105];
void solve(){
    int sum=0;
    for(int i=1;i<=100;i++) t[i]=0;
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        t[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        cin >>b[i];
        t[b[i]]++;
    }
    for(int i=1;i<=100;i++){
        if(t[i]==2) sum++;
    }
    if(n<=m){
        cout <<(n-sum)*2+1<<endl;
    }
    else{
        cout <<(m-sum)*2+2<<endl;
    }
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}