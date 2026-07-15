#include <bits/stdc++.h>
#define int long long
using namespace std;

int T,n,a[200005],b[200005];
vector<int> Q[200005];
void solve(){
    cin >>n;
    for(int i=1;i<=n;i++) Q[i].clear();
    for(int i=1;i<=n;i++){
        cin >>b[i];
        Q[b[i]].push_back(i);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(Q[i].size()%i!=0){
            cout <<-1<<endl;
            return ;
        }
        for(int j=0;j<Q[i].size();j++){
            if((j%i)==0) cnt++;
            a[Q[i][j]]=cnt;
        }
    }
    for(int i=1;i<=n;i++) cout <<a[i]<<" ";
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}