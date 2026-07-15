#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,prime[100005],inq[100005],cnt,a[100005],t[100005];
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
    int qwq;
    cin >>n;
    for(int i=1;i<=n;i++) t[i]=0;
    if(n==2){
        cout <<2<<" "<<1<<endl;
        return ;
    }
    for(int i=1;i<=cnt;i++){
        if(prime[i]>=n/3&&prime[i]<=(2*n)/3){
            qwq=prime[i];
            break;
        }
    }
    a[1]=qwq;
    t[qwq]=1;
    int pos;
    for(int i=2;i<=n;i++){
        int q=i/2,f;
        if(i%2==0) f=1;
        else f=-1;
        if(t[qwq+q*f]==1){
            break;
        }
        if(qwq+q*f>n) break;
        if(qwq+q*f<1) break;
        a[i]=qwq+q*f;
        t[qwq+q*f]=1;
        pos=i;
    }
    for(int i=1;i<=n;i++){
        if(t[i]==0){
            a[++pos]=i;
            t[i]=1;
        }
    }
    for(int i=1;i<=n;i++) cout <<a[i]<<" ";
    cout <<endl;
    return ;
}
signed main(){
    init();
    cin >>T;
    while(T--) solve();
    return 0;
}