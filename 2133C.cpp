#include <bits/stdc++.h>

using namespace std;
int T,n,t[505],vis[505],cnt;
vector<int> ans,qwq[505];
void solve(){
    cin >>n;    
    for(int i=1;i<=n;i++) vis[i]=0,qwq[i].clear();
    ans.clear();
    for(int i=1;i<=n;i++){
        cout <<"? "<<i<<" "<<n<<" ";
        for(int j=1;j<=n;j++){
            cout <<j<<" ";
        }
        cout <<endl;
        int x;
        cin >>x;
        t[i]=x;
        qwq[t[i]].push_back(i);
    }
    int maxn=-1,id;
    for(int i=1;i<=n;i++){
        if(t[i]>maxn){
            maxn=t[i];
            id=i;
        }
    }
    if(maxn==1){
        cout <<"! "<<1<<" "<<1<<endl;
        return ;
    }
    ans.push_back(id);
    for(int i=maxn-1;i>=1;i--){
        for(int j=0;j<qwq[i].size();j++){
        cout <<"? "<<ans[ans.size()-1]<<" "<<2<<" "<<ans[ans.size()-1]<<" "<<qwq[i][j]<<endl;
        int x;
        cin >>x;
        if(x==2){
            ans.push_back(qwq[i][j]);
            break;
        }
    
        }
    
    }
    cout <<"! "<<maxn<<" ";
    for(int i=0;i<ans.size();i++){
        cout <<ans[i]<<" ";
    }
    cout <<endl;

    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}