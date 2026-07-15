#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[2005],b[2005];
struct node{
    int id,pos;
}ans[10005];
void solve(){
    int cnt=0;
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=n;i++) cin >>b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                ans[++cnt].id=1;
                ans[cnt].pos=j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            if(b[j]>b[j+1]){
                swap(b[j],b[j+1]);
                ans[++cnt].id=2;
                ans[cnt].pos=j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]>b[i]){
            ans[++cnt].id=3;
            ans[cnt].pos=i;
        }
    }
    cout <<cnt<<endl;
    for(int i=1;i<=cnt;i++){
        cout <<ans[i].id<<" "<<ans[i].pos<<endl;
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}