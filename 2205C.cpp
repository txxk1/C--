#include <bits/stdc++.h>
using namespace std;
int T,n,nxt[3003],t[1000005],ans[3005],now[1000005],cnt,nowt[1000005];
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
int len,pri[1000005];
int nxtx[1000005];
int nxty[1000005];
//vector<int> a[3005];
struct node{
    int tt[3003];
    int id;
}a[3003];
bool cmp(node q,node p,int x,int y){
    if(q.tt[1]==1e9) return false;
    for(int i=1;i<=ans[x];i++) nxtx[q.tt[i]]=0;
    for(int i=1;i<=ans[y];i++) nxty[p.tt[i]]=0;
    int l=1,r=1;
    
    for(int i=1;i<=3001;i++){
        while((t[q.tt[l]]==1||nxtx[q.tt[l]]==1)&&l<=ans[x]){
            //if(q.tt[l]==1e9) break;
            //cout <<endl<<l<<endl;
            l++;
            
        }
        while((t[p.tt[r]]==1||nxty[p.tt[r]]==1)&&r<=ans[y]){
            //if(p.tt[r]==1e9) break;
            r++;
            
        }
        if(q.tt[l]==p.tt[r]){
            nxtx[q.tt[l]]=1;
            nxty[p.tt[r]]=1;
            l++;
            r++;
            continue;
        }
        return q.tt[l]<p.tt[r];
    }
    return true;
}
void get(int id){
    for(int i=1;i<=ans[id];i++){
        if(a[id].tt[i]==1e9) return ;
        if(t[a[id].tt[i]]==0){
            cout <<a[id].tt[i]<<" ";
            t[a[id].tt[i]]=1;
        }
    }
}
void solve(){
    len=0;
    n=read();
    cnt=0;
    int pricnt=0;
    for(int i=1;i<=n;i++){
        ans[i]=read();
        a[i].id=i;
        for(int j=1;j<=ans[i];j++){
            a[i].tt[j]=read();
            t[a[i].tt[j]]=0;
            nowt[a[i].tt[j]]=0;
            nxt[j]=a[i].tt[j];
        }
        for(int j=1;j<=ans[i];j++){
            a[i].tt[j]=nxt[ans[i]-j+1];
        }
        a[i].tt[ans[i]+1]=0;
        //reverse(a[i].begin(),a[i].end());
    }
    
    //sort(a+1,a+1+n,cmp);
    
    for(int k=1;k<=n;k++){
        int id=1;
        for(int i=1;i<n;i++){
            if(a[i+1].tt[1]!=1e9){
                //cout <<id<<" "<<i+1<<endl;
                if(!cmp(a[id],a[i+1],id,i+1)) id=i+1;
            }
        }
        get(id);
        a[id].tt[1]=1e9;
    }
    cout <<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}
// 2 3 4 3 2 4 11 24 3 1 3 31
// 15324
// 54