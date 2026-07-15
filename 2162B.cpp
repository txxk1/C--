#include <bits/stdc++.h>

using namespace std;
int T,n,a[1005],cnt;
void solve(){
    cnt=0;
    cin >>n;
    char ch=getchar();
    for(int i=1;i<=n;i++){
        char ch=getchar();
        if(ch=='0') a[++cnt]=i;
    }
    cout <<cnt<<endl;
    
    for(int i=1;i<=cnt;i++){
        cout <<a[i]<<" ";
    }
    cout <<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}