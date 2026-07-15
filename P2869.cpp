#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,be[200005];
struct node{
    int x,y,id;
}e[200005];
bool cmp(node a,node b){
    if(a.y==b.y) return a.id<b.id;
    return a.x<b.x;
}
signed main(){
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        cin >>e[i].x>>e[i].y;
        e[i].id=1;
        //be[i]=1e9;
    }
    for(int i=n+1;i<=n+m;i++){
        cin >>e[i].x>>e[i].y;
        e[i].id=2;
        //be[i]=1e9;
    }
    //be[n+m+1]=1e9;
    sort(e+1,e+1+n+m,cmp);
    for(int i=1;i<=m+n;i++){
        if(e[i].id==2){
            be[i]=max(be[i-1],e[i].y);
        }
        else be[i]=be[i-1];
    }
    ll ans=0;
    for(int i=1;i<=n+m;i++){
        if(e[i].id==1){
            int now=lower_bound(be+1,be+1+i,e[i].x)-be;
            while(e[now].id==1) now++;
            ans+=(ll)e[now].x;
        }
    }
    cout <<ans;
    return 0;
}