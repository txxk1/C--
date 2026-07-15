#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+(ch-'0');
        ch=getchar();
    }
    return s*f;
}
int T,n,m,k,cnt[400005],sum[400005];
char ch;
struct node{
    int x,id;
}h[400005];
bool cmp(node a,node b){
    return a.x<b.x;
}
vector<int> Q[400005];
void solve(){
    n=read();
    m=read();
    k=read();
    
    for(int i=1;i<=n;i++){
        cnt[i]=0;
        sum[i]=0;
    }
    for(int i=1;i<=n;i++){
        h[i].x=read();
        h[i].id=i;
        for(int j=1;j<=m;j++){
            int x;
            cin >>x;
            Q[i].push_back(x);
            if(x!=-1) cnt[i]+=x;
            else sum[i]++;
        }
    }
    sort(h+1,h+1+n,cmp);
    int now=cnt[h[1].id],lnow=-1,flag=0;
    for(int i=0;i<m;i++){
        if(Q[h[1].id][i]==-1) Q[h[1].id][i]=0;
    }
    for(int i=2;i<=n;i++){
        if(h[i].x==h[i-1].x){
            if(cnt[h[i].id]+sum[h[i].id]*k<=lnow){
                flag=1;
                break;
            }
            else{
                int qwq=lnow-cnt[h[i].id]+1;
                if(qwq<=0){
                    for(int j=0;j<m;j++){
                        if(Q[h[i].id][j]==-1) Q[h[i].id][j]=0;
                    }
                    now=max(now,cnt[h[i].id]);
                }
                else{
                    for(int j=0;j<m;j++){
                        if(Q[h[i].id][j]==-1){
                            if(qwq>=k) Q[h[i].id][j]=k,qwq-=k;
                            else Q[h[i].id][j]=qwq,qwq=0;
                        }
                    } 
                    now=max(now,lnow+1);
                }
            }
        }
        else{
            lnow=max(now,lnow);
            now=0;
            if(cnt[h[i].id]+sum[h[i].id]*k<=lnow){
                flag=1;
                break;
            }
            else{
                int qwq=lnow-cnt[h[i].id]+1;
                if(qwq<=0){
                    for(int j=0;j<m;j++){
                        if(Q[h[i].id][j]==-1) Q[h[i].id][j]=0;
                    }
                    now=cnt[h[i].id];
                }
                else{
                    for(int j=0;j<m;j++){
                        if(Q[h[i].id][j]==-1){
                            if(qwq>=k) Q[h[i].id][j]=k,qwq-=k;
                            else Q[h[i].id][j]=qwq,qwq=0;
                        }
                    }                   
                    now=lnow+1;
                }
            }
        }
    }
    if(flag==1) cout <<"No"<<endl;
    else{
        cout <<"Yes"<<endl;
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                cout <<Q[i][j]<<" ";
            }
            cout <<endl;
        }
    }
    for(int i=1;i<=n;i++){
        Q[i].clear();
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}