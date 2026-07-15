#include <bits/stdc++.h>
#define int long long
using namespace std;
int T;
string a;
void solve(){
    cin >>a;
    int n=a.size(),flag=0;
    for(int i=1;i<n;i++){
        if(a[i-1]=='*'&&a[i]=='*') flag=1;
        if(a[i-1]=='*'&&a[i]=='<') flag=1;
        if(a[i-1]=='>'&&a[i]=='*') flag=1;
        if(a[i-1]=='>'&&a[i]=='<') flag=1;
    }
    if(flag==1){
        cout <<-1<<endl;
        return ;
    }
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(a[i]=='<'||a[i]=='*') cnt1++;
        else break;
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]=='>'||a[i]=='*') cnt2++;
        else break;
    }
    cout <<max(cnt1,cnt2)<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// >>>>
// <*>