#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,s[300005];
vector<int> Q[300005];
void solve(){
    int sum=0ll;
    cin >>n>>m;
    for(int i=1;i<=n;i++) Q[i].clear(),s[i]=0;
    for(int i=1;i<=n;i++){
        int qwq=0ll;
        for(int j=1;j<=m;j++){
            int x;
            cin >>x;
            Q[i].push_back(x);
            qwq+=x;
        }
        s[i]=qwq;
        sum+=qwq;
    }
    int x=sum/2;
    cout <<x*(sum-x)<<endl;
    int now=1,ans=0ll;
    while(now<=n&&ans<=x){
        ans+=s[now];
        now++;
        //cout <<now<<" "<<ans<<endl;
    }
    // 4 3
    // 5 4
    //4 2
    now--;
    ans-=s[now];
    now--;
    int pos=m;
    for(int i=1;i<=now;i++) cout <<"D";
    for(int j=m-1;j>=0;j--){
        if(Q[now+1][j]==1){
            ans++;
            if(ans==x){
                pos=j;
                break;
            }
        }
    }
    for(int i=1;i<=pos;i++) cout <<"R";
    cout <<"D";
    for(int i=pos+1;i<=m;i++) cout <<"R";
    for(int i=now+1;i<n;i++) cout <<"D";
    cout <<"\n";
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
}