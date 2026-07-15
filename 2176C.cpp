#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,f[200005],odd[200005],oddcnt,even[200005],evencnt;
int a[200005];
void solve(){
    int S=0;
    oddcnt=0;
    evencnt=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        if(a[i]%2==0) even[++evencnt]=a[i],S+=a[i];
        else odd[++oddcnt]=a[i];
    }
    sort(odd+1,odd+1+oddcnt);
    sort(even+1,even+1+evencnt);
    if(oddcnt==0){
        for(int i=1;i<=n;i++){
            cout <<0<<" ";
        }
        cout <<endl;
        return ;
    }
    if(evencnt==0){
        for(int i=1;i<=n;i++){
            if(i%2==0) cout <<0<<" ";
            else cout <<odd[oddcnt]<<" ";
        }
        cout <<endl;
        return ;
    }
    f[1]=odd[oddcnt];
    for(int i=1;i<=evencnt;i++){
        f[i+1]=f[i]+even[evencnt-i+1];
    }
    for(int i=evencnt+2;i<=n;i++){
        if((i-evencnt)%2==1) f[i]=f[1]+S;
        else f[i]=f[1]+S-even[1];
    }
    if(oddcnt%2==0) f[n]=0;
    for(int i=1;i<=n;i++){
        cout <<f[i]<<" ";
    }
    cout <<endl;
    return ;
}
// 一个奇数加尽可能多的偶数
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}