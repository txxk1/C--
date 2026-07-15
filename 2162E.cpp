#include <bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;
int T,n,k,a[200005],t[200005],ans[200005];
int f(int x){
    if(x==n) return 1;
    return x+1;
}
void solve(){
    cin >>n>>k;
    for(int i=1;i<=n;i++) t[i]=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        t[a[i]]++;
    }
    int flag=0,tid,cnt=0;
    for(int i=1;i<=n;i++){
        if(t[i]==0){
            flag=1;
            tid=i;
            cnt++;
        }
    }
    if(flag){
        ans[1]=tid;
        if(f(tid)==a[n]) ans[2]=f(f(tid));
        else ans[2]=f(tid);
        /*
        for(int i=2;i<=k;i++){
            if(a[n+2-i]==now){
                now=f(now);
                cout <<now<<" ";
            }
            else cout <<now<<" ";
            now=f(now);
        }
        cout <<endl;*/
        for(int i=3;i<=k;i++){
            if(f(ans[i-1])==ans[i-2]) ans[i]=f(f(ans[i-1]));
            else ans[i]=f(ans[i-1]);
        }
        for(int i=1;i<=k;i++){
            cout <<ans[i]<<" ";
        }
        cout <<endl;
    }
    else{
        for(int i=1;i<=k;i++){
            cout <<a[i]<<" ";
        }
        cout <<endl;
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}