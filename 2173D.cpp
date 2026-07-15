#include <bits/stdc++.h>
#define inf 2000000000
#define int long long
using namespace std;
int T,n,k,t[66],fa[66],f[66][66][3];

void solve(){
        // f[i][j] 前i位j次操作最多进位
    memset(t,0,sizeof(t));
    int sum=0;
    cin >>n>>k;
    int cnt=0,pcnt=0;
    for(int i=0;i<=30;i++){
        t[i]=(n&(1<<i))!=0;
        if(t[i]==1) pcnt++;
        /*
        if((n&(1<<i))!=0){
            sum+=__builtin_popcount(n)-__builtin_popcount(n+(1<<i))+1;
            n+=(1<<i);
            cnt++;
            if(k==cnt){
                cout <<sum<<endl;
                return ;
            }
        }
        */
    }
    for(int tt=1;tt<=30;tt++){        

        int maxn=-1,id;
        for(int i=0;i<=60;){
            if(t[i]!=0){
                int qwq=i+1;
                while(t[qwq]==1) qwq++;
                if(qwq-i>maxn){
                    maxn=qwq-i;
                    id=i;
                }
                i=qwq;
            }
            else i++;
        }
        cnt++;
        pcnt++;
        for(int i=id;;i++){
            if(t[i]>1){
                t[i]=0;
                t[i+1]++;
                pcnt--;
                sum++;
            }
            else break;
        }
        if(cnt==k){
            cout <<sum<<endl;
            return ;
        }
        if(pcnt==1) break;
    }
    cout <<k-cnt+sum<<endl;
}
void solve_std(){
    cin >>n>>k;
    int popcnt=__builtin_popcount(n);
    if(k>=64){
        cout <<k+popcnt-1<<endl;
        return ;
    }
    for(int i=0;i<=64;i++){
        for(int j=0;j<=64;j++){
            f[i][j][0]=inf;
            f[i][j][1]=inf;
        }
    }
    f[0][0][0]=0;
    for(int i=0;i<64;i++){
        int qwq=(n&(1ll<<i));
        int now=(qwq!=0);
        for(int j=0;j<=k;j++){
            for(int x=0;x<2;x++){
                int res=(now+x)%2,pre=(now+x)/2;
                if(f[i][j][x]!=inf){
                    f[i+1][j][pre]=min(f[i+1][j][pre],f[i][j][x]+res);
                    if(j<k){
                        int res=(now+x+1)%2;
                        int pre=(now+x+1)/2;
                        f[i+1][j+1][pre]=min(f[i+1][j+1][pre],f[i][j][x]+res);
                    }
                }
            }
        }
    }
    int ans=inf;
    for(int i=0;i<=k;i++){
        if(f[64][i][0]!=inf) ans=min(ans,f[64][i][0]);
        if(f[64][i][1]!=inf) ans=min(ans,f[64][i][1]+1);
    }
    cout <<k+popcnt-ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve_std();
    return 0;
}
//
// 11101100
//1000011 3
//1000100 5
// 111100 2
//1000000 6
// 110100
// 111000 1
//1000000 6