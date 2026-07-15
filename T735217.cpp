#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,t,b[100005];
string a[100005];
struct node{
    string qwq;
    int s;
}game[100005];
bool cmp(node x,node y){
    return x.s<y.s;
}
void solve(){
    int pos=-1,cnt=0;
    cin >>t>>n;
    t=t*60;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        if(a[i]=="OwsHonkaiStarRail"){
            pos=i;
        }
    }
    for(int i=1;i<=n;i++){
        cin >>b[i];
        if(i==pos) continue;
        game[++cnt].qwq=a[i];
        game[cnt].s=b[i];
    }
    if(pos==-1||t<b[pos]){
        cout <<-1<<endl;
        return ;
    }
    t-=b[pos];
    sort(game+1,game+1+cnt,cmp);
    cout <<"OwsHonkaiStarRail ";
    for(int i=1;i<=cnt;i++){
        if(t>=game[i].s){
            cout <<game[i].qwq<<" ";
            t-=game[i].s;
        }
    }
    return ;
}
signed main(){
    solve();
    return 0;
}