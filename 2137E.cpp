#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[200005],t[200005];
int get(){
    int sum=0,cnt=0;
    int qwq;
    for(int i=0;i<=n;i++){
        if(t[i]==0){
            qwq=i;
            break;
        } 
    }
    for(int i=0;i<=n;i++){
        if(t[i]>1){
            cnt+=t[i];
        }
        if(t[i]==1){
            if(i>qwq) cnt++;
            else sum+=i;
        }
    }
    return sum+cnt*qwq;
}
void solve(){
    cin >>n>>k;
    for(int i=0;i<=n;i++) t[i]=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        t[a[i]]++;
    }
    
    int now,res;
    int flag=1;
    for(int i=0;i<=n;i++){
        if(t[i]!=1){
            now=i;
            break;
        }
    }
    if(t[now]>1) flag=0;
    else flag=1;
    int ans=now*(now-1)/2;
    if(k==1){
        cout <<get()<<endl;
        return ;
    }
    int ad=now*(n-now);
    if((k+flag)%2==0){
        cout <<ans+ad<<endl;
    }
    else{
        cout <<ans+ad+n-now<<endl;
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}