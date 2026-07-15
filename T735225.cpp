#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,t,f[1005][1005];
int a[1005];
int F(int l,int r){
    if(l>r) return 0;
    if(l==r) return f[l][r]=a[l];
    if(a[l]>=a[r]){
        return f[l][r]=a[l]+min(F(l+1,r-1),F(l+2,r));
    }
    else return f[l][r]=a[r]+min(F(l+1,r-1),F(l,r-2));
}
void solve(){
    int sum=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        f[i][i]=a[i];
        f[i][i-1]=0;
        sum+=a[i];
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            if(a[i]>=a[j]) f[i][j]=a[i]+min(f[i+1][j-1],f[i+2][j]);
            else f[i][j]=a[j]+min(f[i+1][j-1],f[i][j-2]);
        }
    }
    int x=0;
    cout <<f[1][n]<<" "<<sum-f[1][n]<<endl;
    return ;
}
signed main(){
    solve();
    return 0;
}