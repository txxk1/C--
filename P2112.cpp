#include <iostream>
#include <cstring>
using namespace std;
int n,K,a[1001],s[1001];
double f[1001][21],avg;
char b[22];
int main(){
    cin >>n>>K;
    for(int i=1;i<=n;i++){
        cin >>b;
        a[i]=strlen(b);
        s[i]=s[i-1]+a[i];
        avg+=(double)a[i];
    }
    avg=(double)s[n]/K;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=K;j++){
            f[i][j]=1000000000.00;
        }
        f[i][1]=(s[i]-avg)*(s[i]-avg)/K;
    }
    for(int k=2;k<=K;k++){
        for(int i=k;i<=n;i++){
            for(int j=1;j<=i-1;j++){
            
                f[i][k]=min(f[j][k-1]+(s[i]-s[j]-avg)*(s[i]-s[j]-avg)/K, f[i][k]);
            }
        }
    }
    printf("%.1f",f[n][K]);
    return 0;
}