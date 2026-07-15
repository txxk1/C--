#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200005],s[200005],cnt;
void solve(){
    cnt=0;
    int ans=0,sum=0,qwq=0,flag=0;
    map<int,int> Q;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        Q[a[i]]++;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(Q[a[i]]%2==1){
            s[++cnt]=a[i];
            ans+=(Q[a[i]]-1)*a[i];
            qwq+=Q[a[i]]-1;
        }
        else{
            ans+=(Q[a[i]])*a[i];
            qwq+=Q[a[i]];
        }
        i=i+Q[a[i]]-1;
    }
    if(ans==0){
        cout <<0<<endl;
        return ;
    }
    if(qwq==2){
        flag=1;
    }
    for(int i=1;i<=cnt;i++){
        if(s[i]-s[i-1]<ans){
            sum=max(sum,s[i]+s[i-1]);
            flag=0;
        }
        else if(s[i]<ans){
            sum=max(sum,s[i]);
            flag=0;
        }
    }
    if(flag) cout <<0<<endl;
    else cout <<ans+sum<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}