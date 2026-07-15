#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
int a[15],ahp[15],at[15],acnt[15];
int b[15],bhp[15],bt[15],bcnt[15];
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
double sa=0.00,sb=0.00,sum=0.00;
void dfs(int id,int nowa,int nowb,double pos){
    int now=0;
    if(nowa==0&&nowb==0) sum+=pos;
    if(nowa==0&&nowb!=0) sb+=pos;
    if(nowb==0&&nowa!=0) sa+=pos;
    if(nowa==0||nowb==0) return ;
    int qwqa=nowa,qwqb=nowb;
    int shenmi=100;
    //cout <<nowa<<" "<<nowb<<" "<<pos<<endl;
    if(id==1){
        for(int i=1;i<=n;i++){
            if(ahp[i]>0)shenmi=min(shenmi,acnt[i]);
        }
        for(int i=1;i<=n;i++){
            if(acnt[i]==shenmi&&ahp[i]>0){
                now=i;
                break;
            }
        }
        acnt[now]++;
        for(int i=1;i<=m;i++){
            if(bhp[i]>0){
                bhp[i]-=at[now];
                ahp[now]-=bt[i];
                if(bhp[i]<=0) qwqb--;
                if(ahp[now]<=0) qwqa--;
                dfs(id^1,qwqa,qwqb,(double)pos/nowb);
                if(bhp[i]<=0) qwqb++;
                if(ahp[now]<=0) qwqa++;
                bhp[i]+=at[now];
                ahp[now]+=bt[i];

            }
        }
        acnt[now]--;
    }
    else{
        for(int i=1;i<=m;i++){
            if(bhp[i]>0)shenmi=min(shenmi,bcnt[i]);
        }
        for(int i=1;i<=m;i++){
            if(bcnt[i]==shenmi&&bhp[i]>0) {
                now=i;
                break;
            }
        }
        bcnt[now]++;
        for(int i=1;i<=n;i++){
            if(ahp[i]>0){
                ahp[i]-=bt[now];
                bhp[now]-=at[i];
                if(ahp[i]<=0) qwqa--;
                if(bhp[now]<=0) qwqb--;
                dfs(id^1,qwqa,qwqb,(double)pos/nowa);
                if(ahp[i]<=0) qwqa++;
                if(bhp[now]<=0) qwqb++;
                ahp[i]+=bt[now];
                bhp[now]+=at[i];
            }
        }
        bcnt[now]--;
    }
}
void solve(){
    int ans=0;
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        ahp[i]=a[i];
        at[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        b[i]=read();
        bhp[i]=b[i];
        bt[i]=b[i];
    }
    if(n>m) dfs(1,n,m,1.00);
    if(n<m) dfs(0,n,m,1.00);
    if(n==m){
        dfs(1,n,m,0.50);
        dfs(0,n,m,0.50);
    }        
    printf("%.9lf\n",(double)sa);
    printf("%.9lf\n",(double)sb);
    printf("%.9lf\n",(double)sum);
    return ;
}
signed main(){
    solve();
    return 0;
}
/*
6 6
1 1 4 5 1 4
1 1 4 5 1 4
*/