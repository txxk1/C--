#include <bits/stdc++.h>

using namespace std;
int T,n,t[5];
struct node{
    int s;
    int maxn,maxid;
    int minn,minid;
}nem[100005];
bool cmp(node q,node w){
    return q.s>w.s;
}
struct club{
    int id,x;
}a[5];
bool cmpc(club q,club w){
    return q.x>w.x;
}
void solve(){
    int ans=0;
    t[1]=0;
    t[2]=0;
    t[3]=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[1].x>>a[2].x>>a[3].x;
        a[1].id=1;
        a[2].id=2;
        a[3].id=3;
        sort(a+1,a+4,cmpc);
        nem[i].maxn=a[1].x;
        nem[i].maxid=a[1].id;
        nem[i].minn=a[2].x;
        nem[i].minid=a[2].id;
        nem[i].s=nem[i].maxn-nem[i].minn;
    }
    sort(nem+1,nem+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(t[nem[i].maxid]==n/2){
            ans+=nem[i].minn;
            t[nem[i].minid]++;
        }
        else{
            ans+=nem[i].maxn;
            t[nem[i].maxid]++;
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