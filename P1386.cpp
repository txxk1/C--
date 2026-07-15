#include <bits/stdc++.h>
using namespace std;
long long T,n,m;
long long M,a[303],f[303][303],C[303][303],s[303];
void solve(){
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    memset(C,0,sizeof(C));
    memset(s,0,sizeof(s));
    cin >>n>>m>>M;
    for(int i=1;i<=m;i++){
        int k,x;
        cin >>k>>x;
        a[x]++;
    }
    C[0][0]=1;
    C[1][0]=1;
    C[1][1]=1;
    for(int i=2;i<=n;i++){
        C[i][0]=1;
        C[i][i]=1;
        for(int j=1;j<=i-1;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
        }
    }
    s[n]=a[n];
    for(int i=n;i>=1;i--){
        if(s[i]>n-i+1){
            cout <<"NO"<<endl;
            return ;
        }
        s[i-1]=s[i]+a[i-1];
    }
/*
s4=0 s3=0 s2=1 s1=2;
i=3 j<=2
i=2 j<=2
i=1 j<=2
f41=f42=f40=1
f32=2*1+1+1=4
f30=f40=1
f31=2
f20=1 f21=f31+f30=3 f22=f30+2f31+f32=1+4+4
f12=f20+f22+2f21=1+9+6
*/
    //f[n+1][0]=1;
    for(int i=0;i<=n-s[n]+1;i++) f[n][i]=1;

    for(int i=n-1;i>=1;i--){
        for(int j=0;j<=n-i-s[i]+1;j++){
            for(int k=0;k<=j;k++){
                f[i][j]=(f[i][j]+C[j][k]*f[i+1][j-k]%M)%M;
            }
        }
    }
    cout <<"YES "<<f[1][n-m]<<endl;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}