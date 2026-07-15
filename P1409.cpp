#include <iostream>
#include <cstdio>

using namespace std;
int n,m;
double f[1003][1003];
int main(){
    cin >>n>>m;
    f[1][1]=1.00;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1) f[i][j]=1;
        }
    }
    printf("%.9lf",f[n][m]);
    return 0;
}