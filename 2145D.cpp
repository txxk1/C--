#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,f[33][701],a[33];
void init(){
    f[0][0]=1;
    f[1][0]=1;
    f[2][1]=1;
    f[2][0]=1;
    for(int i=0;i<=30;i++){
        for(int j=0;j<=i*(i-1)/2;j++){
            if(f[i][j]==0) continue;
            for(int k=1;k+i<=30;k++){
                f[i+k][j+(k-1)*k/2]=1;
            }
        }
    }
}
vector<int> Q;
void dfs(int x,int y){
    if(x==0) return ;
    for(int i=1;i<=n;i++){
        if(f[x-i][y-(i-1)*i/2]==1){
            Q.push_back(i);
            dfs(x-i,y-i*(i-1)/2);
            break;
        }
    }
}
void solve(){
    Q.clear();
    cin >>n>>k;
    for(int i=1;i<=n;i++) a[i]=n-i+1;
    k=(n-1)*n/2-k;
    if(f[n][k]==0) cout <<0<<endl;
    else{
        dfs(n,k);
        int cnt=n;
        for(int i=0;i<Q.size();i++){
            for(int j=cnt-Q[i]+1;j<=cnt;j++){
                cout <<j<<" ";
            }
            cnt=cnt-Q[i];
        }
        cout <<endl;
    }
    return ;
}
signed main(){
    init();
    cin >>T;
    while(T--) solve();
    return 0;
}