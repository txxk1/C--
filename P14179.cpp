#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,D,m,a[1000005],ans[1000005];
bool check(int id,int x){
    if(a[id]==1){
        if((ans[id]+m)%D==0) return true;
        else return false;
    }
    else{
        if((ans[id]+m)%D==0) return false;
        else return true;
    }
}
void update(int id,int &m){
    if(a[id]==1){
        int now=m/D;
        ans[id]+=now*D;
        m-=now*D;
    }
    else{
        if((ans[id]+m)%D!=0){
            ans[id]+=m;
            m=0;
        }
        else{
            ans[id]+=m-1;
            m=1;
        }
    }
}
void print(){
    for(int i=1;i<=n;i++){
        cout <<ans[i]<<" ";
    }
    cout <<endl;
    return ;
}
void solve(){
    cin >>n>>D>>m;
    for(int i=1;i<=n;i++) cin >>a[i];
    if(a[1]==1) ans[1]=0;
    if(a[1]==0){
        ans[1]=1;
        m--;
    }
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            ans[i]=ans[i-1];
        }
        else{
            if(a[i]==0&&a[i-1]==1) ans[i]=ans[i-1]+1;
            else{
                int qwq=ans[i-1]/D;
                ans[i]=(qwq+1)*D;
            }
        }
        m-=ans[i];
    }
    if(m<0){
        cout <<"NO"<<endl;
        return ;
    }
    int qwq=n;
    while(m>0&&qwq>=1){
        update(qwq,m);
        qwq--;
    }
    if(m>0){
        cout <<"NO"<<endl;
        return ;
    }
    print();
    return ;
}
signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}