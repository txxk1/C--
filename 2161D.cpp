#include <bits/stdc++.h>

using namespace std;
int T,n,x,a[300005],t[300005],f[300005][3];
void solve(){
    cin >>n;
    for(int i=1;i<=n;i++) t[i]=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    // f[i][0/1] 前 i 个数 去除/保留的min
    f[1][0]=0;
    f[1][1]=1;
    t[a[1]]++;
    for(int i=2;i<=n;i++){
        
        if(a[i]==a[i-1]+1){
            f[i][0]=max(f[i-1][1],f[i-1][0]);
            f[i][1]=1;
        }
        t[a[i]]++;
    }
    //
    cout <<min(f[n][0],f[n][1])<<endl;
    // 1 2 3 4 5
    // 1 1 2 2 3
    // 0 1 1 2 2
    return ;
}
int main(){
	cin >>T;
    while(T--) solve();
	return 0;
}
