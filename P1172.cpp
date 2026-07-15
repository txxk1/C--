#include <iostream>
#include <cstring>
using namespace std;

const int maxn=(1<<20)+3;
int n,s[22][22],f[maxn][22],ans;

int main(){
    cin >>n;
    memset(f,sizeof(f),0x3f);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>s[i][j];
        }
        f[1<<(i-1)][i]=0;
    }

    for(int i=0;i<(1<<n);i++){
        for(int j=1;j<=n;j++){
            if( (i&(1<<(j-1))) != 0 ){
                for(int k=1;k<=n;k++){
                    if( (i&(1<<(k-1))) == 0) f[i+(1<<(k-1))][k]=max(f[i+(1<<(k-1))][k],f[i][j]+s[j][k]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++) ans=min(ans,f[(1<<n)-1][i]+s[i][1]);
    cout <<ans;
    return 0;
}