#include <bits/stdc++.h>
#define int long long
using namespace std;
int m,n,a[1000005],t[1000005];
vector<int> s[1000005];
struct node{
    int l,r;
}e[1000005];
bool cmp(node x,node y){
    return x.l<y.l;
}
void solve(){
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        s[a[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        cin >>e[i].l>>e[i].r;
    }
    sort(e+1,e+1+m,cmp);
    int now=0,u=0;
    for(int i=1;i<=m;i++){
        int flag=0;
        for(int j=i+1;j<=m;j++){
            if(e[j].r>e[i].r) break;
            else flag=1;
        }
        if(flag==1) e[i].l=1e9;
    }
    for(int i=1;i<=m;i++){
        if(e[i].l==1e9) continue;
        while(u<e[i].r){
            u++;
            t[a[u]]++;
        }
        while(now<e[i].l){
            now++;
            t[a[now]]--;
        }
        
    }
    return ;
}
signed main(){
    solve();
    return 0;
}