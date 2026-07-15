#include <bits/stdc++.h>
using namespace std;
int T,n,k,t[205];
char a[105];
void solve(){
    int sum=0;
    cin >>n>>k;
    for(int i=1;i<=n;i++) t[i]=0;
    scanf("%s",a+1);
    for(int i=1;i<=n;i++){
        if(a[i]=='1'){
            for(int j=i;j<=i+k;j++) t[j]=1;
        }
        if(a[i]=='0'){
            if(t[i]==0) sum++;
        }
    }
    cout <<sum<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}