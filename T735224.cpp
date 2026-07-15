#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,p[500005],q[500005],pcnt,qcnt;
char a[1000005];
char na[1000005];
char nb[1000005];
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return s*f;
}
void solve(){
    int ansa=0,ansb=0;
    cin >>n;
    cin >>a;
    na[0]='A';
    nb[0]='B';
    for(int i=1;i<2*n;i++){
        if(na[i-1]=='A') na[i]='B';
        else na[i]='A';
        if(nb[i-1]=='A') nb[i]='B';
        else nb[i]='A';
    }
    int maxn=-1,minn=1e7;
    for(int i=0;i<2*n;i++){
        if(a[i]!=na[i]){
            minn=min(minn,i+1);
            maxn=max(maxn,i+1);
            if(a[i]=='A') p[++pcnt]=i;
            else q[++qcnt]=i;
        }
    }
    for(int i=1;i<=pcnt;i++){
        ansa+=abs(p[i]-q[i]);
    }
    //ansa=maxn-minn;
    maxn=-1,minn=1e7;
    qcnt=0;
    pcnt=0;
    for(int i=0;i<2*n;i++){
        if(a[i]!=nb[i]){
            minn=min(minn,i+1);
            maxn=max(maxn,i+1);
            if(a[i]=='A') p[++pcnt]=i;
            else q[++qcnt]=i;
        }
    }
    for(int i=1;i<=pcnt;i++){
        ansb+=abs(p[i]-q[i]);
    }
    cout <<min(ansa,ansb)<<endl;
    return ;
}
signed main(){
    solve();
    return 0;
}