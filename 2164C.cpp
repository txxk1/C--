#include <bits/stdc++.h>

using namespace std;
int T,n,m,a[200005],res1[200005];
struct node{
    int b,c;
}mon1[200005],mon2[200005],mon[200005];
bool cmp(node x,node y){
    return x.b<y.b;
}
void solve(){
    cin >>n>>m;
    int cnt1=0,cnt2=0,ans=0;
    int cntres=0;
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=m;i++) cin >>mon[i].b;
    for(int i=1;i<=m;i++) cin >>mon[i].c;
    for(int i=1;i<=m;i++){
        if(mon[i].c==0){
            mon1[++cnt1].b=mon[i].b;
            mon1[cnt1].c=mon[i].c;
        }
        else{
            mon2[++cnt2].b=mon[i].b;
            mon2[cnt2].c=mon[i].c;
        }
    }
    sort(a+1,a+1+n);
    sort(mon2+1,mon2+1+cnt2,cmp);
    sort(mon1+1,mon1+1+cnt1,cmp);
    mon1[cnt1+1].b=2e9;
    mon2[cnt2+1].b=2e9;
    int now=1;
    priority_queue<int,vector<int>,greater<int> > Q;/*
    for(int i=1;i<=n;i++){
        int x=a[i];
        while(mon2[now].b<=x){
            x=max(mon2[now].c,x);
            now++;
            ans++;
        }
        res[++cnt]=x;
    }*/
    for(int i=n;i>=1;i--) Q.push(a[i]);
    while(!Q.empty()){
        int qwq=Q.top();
        Q.pop();
        if(qwq>=mon2[now].b){
            Q.push(max(qwq,mon2[now].c));
            now++;
            ans++;
        }
        else res1[++cntres]=qwq;
    }
    sort(res1+1,res1+1+cntres);
    now=1;
    for(int i=1;i<=cntres;i++){
        if(res1[i]>=mon1[now].b){
            now++;
            ans++;
        }
    }
    cout <<ans<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}