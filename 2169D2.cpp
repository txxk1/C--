#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y,k;
int ck(int mid,int x,int y){
    int N=mid,t=x;
    while(t>0&&(N/y)!=0){
        int qwq=N/y;
        int nxt=qwq*y;
        int cnt=(N-nxt)/qwq;
        if(t>=cnt){
            N-=cnt*qwq;
            t-=cnt;
        }
        else{
            N-=t*qwq;
            t=0;
        }
        if(N/y==qwq&&t>0){
            N-=qwq;
            t--;
        }
        if(N<k) return N>=k;
    }
    return N>=k;
}
void solve(){
    cin >>x>>y>>k;
    int now=k;
    int t=x;
    if(y==1){
        cout <<-1<<endl;
        return ;
    }
    while(t>0&&now<=1e12){
        int qwq=(now-1)/(y-1);
        if(qwq==0) break;
        int nxt=(qwq+1)*(y-1);
        int cnt=(nxt-now)/qwq+1;
        if(t>=cnt){
            now+=qwq*cnt;
            t-=cnt;
        }
        else{
            now+=qwq*t;
            t=0;
        }
    }
    if(now>1e12) cout <<-1<<endl;
    else cout <<now<<endl;
    return ;        
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
/*
10
735748 370000 136899260000
735748 370000 136899260001
735748 370000 136899260002
735748 370000 136899260003
735748 370000 136899260004
735748 370000 136899260005
735748 370000 136899260006
735748 370000 136899260007
735748 370000 136899260008
735748 370000 136899260009
*/