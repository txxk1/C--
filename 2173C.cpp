#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[200005],cntans,ans[200005];
int prime[100005],inq[100005],cnt,t[100005];
void init(){
    //inq[2]=1;
    for(int i=2;i<=100000;i++){
        if(inq[i]==0) prime[++cnt]=i;
        for(int j=1;j*i<=100000;j++){
            inq[i*j]=1;
        }
    }
    //for(int i=1;i<=100;i++) cout <<prime[i]<<endl;
}
void solve(){
    cntans=0;
    map<int,int> f;
    map<int,int> q;
    int sum=0,flag=0;
    cin >>n>>k;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        f[a[i]]=1;
        if(k/a[i]>n){
            flag=1;
        }
    }
    if(flag==1){
        cout <<-1<<endl;
        return ;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(q[a[i]]==1) continue;
        for(int j=1;j*a[i]<=k;j++){
            if(f[j*a[i]]==0){
                cout <<-1<<endl;
                return ;
            }
            q[j*a[i]]=1;
        }
        ans[++cntans]=a[i];
    }
    cout <<cntans<<endl;
    for(int i=1;i<=cntans;i++){
        cout <<ans[i]<<" ";
    }
    cout <<endl;
    //
    return ;
}
signed main(){
    init();
    cin >>T;
    while(T--) solve();
    return 0;
}
// >k