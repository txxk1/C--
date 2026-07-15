#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,T;

void solve(){

    cin >>n>>m;
    vector<int> a[250005];
    vector<int> u[250005],d[250005],l[250005],r[250005];
    
    for(int i=1;i<=n;i++){
        for(int i=1;i<=m;i++){
            char ch=getchar();
            a[i].push_back(ch-'0');
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i][0]==0) l[i].push_back(1e7);
        else l[i].push_back(0);
        for(int j=1;j<m;j++){
            if(a[i][j]==1) l[i].push_back(j);
            else l[i].push_back(l[i][j-1]);
        }
        if(a[i][m-1]==0) r[i].push_back(1e7);
        else r[i].push_back(m-1);
        for(int j=m-2;j>=0;j--){
            if(a[i][j]==1) r[i].push_back(j);
            else r[i].push_back(r[i][m-j-2]);
        }
    }
    for(int i=0;i<m;i++){
        if(a[1][i]==0) u[i].push_back(1e7);
        else u[i].push_back(1);
        for(int j=2;j<=n;j++){
            if(a[j][i]==1) u[i].push_back(j);
            else u[i].push_back(u[i][j-1]);
        }
        if(a[n][i]==0) d[i].push_back(1e7);
        else d[i].push_back(n);
        for(int j=n-1;j>=1;j--){
            if(a[j][i]==1) d[i].push_back(j);
            else d[i].push_back(d[i][n-j-1]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(l[i][j]==1e7||r[i][m-j-1]==1e7||u[j][i-1]==1e7||d[j][n-i]==1e7){
                cout <<0<<" ";
            }
            else{
                cout <<(r[i][m-j-1]-l[i][j])*(d[j][n-i]-u[j][i-1])<<" ";
            }
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