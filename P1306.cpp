#include <iostream>
#define mod 100000000
using namespace std;

long long n,m,ans[3][3],a[3][3],nxt[3][3],d;
long long gcd(long long x,long long y){
    if(y==0) return x;
    else return gcd(y,x%y);
}
void cross1(){
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            nxt[i][j]=0;
        }
    }
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            for(int k=1;k<=2;k++){
                nxt[i][j]=(nxt[i][j]+ans[i][k]*a[k][j])%mod;
            }
        }
    }
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            ans[i][j]=nxt[i][j];
        }
    }
}
void cross2(){
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            nxt[i][j]=a[i][j];
            a[i][j]=0;
        }
    }
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            for(int k=1;k<=2;k++){
                a[i][j]=(a[i][j]+nxt[i][k]*nxt[k][j])%mod;
            }
        }
    }
}
int main(){
    cin >>n>>m;
    d=gcd(n,m);
    d=d-2;
    a[1][1]=1;
    a[1][2]=1;
    a[2][1]=1;
    a[2][2]=0;
    ans[1][1]=1;
    ans[1][2]=1;
    while(d){
        if(d%2==1) cross1();
        cross2();
        d=d/2;
    }
    cout <<ans[1][1];
    return 0;
}