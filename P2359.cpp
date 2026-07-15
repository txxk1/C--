#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+9;
int n,f[10005][100],ans;
int check(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return 1;
    }
    return 0;
}
int main(){
    cin >>n;
    for(int i=3;i<=n;i++){
        for(int j=11;j<=99;j++){
            int a=j/10,b=j%10;
            if(a==0||b==0) continue;
            f[2][j]=1;
            for(int c=1;c<=9;c++){
                if(check(j*10+c)==0) f[i][b*10+c]=(f[i][b*10+c]+f[i-1][j])%mod;
            }
        }
    }
    for(int i=11;i<=99;i++){
        int a=i/10,b=i%10;
        if(a==0||b==0) continue;
        ans=(ans+f[n][i])%mod;
    }
    cout <<ans;
    return 0;
}