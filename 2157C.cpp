#include <bits/stdc++.h>
#define int long long
#define inf 1e9
using namespace std;
int T,n,k,q,a[105],v[105];
struct node{
    int c,l,r;
}e[105];
bool cmp(node a,node b){
    return a.l<b.l;
}
void solve(){
    cin >>n>>k>>q;
    for(int i=1;i<=n;i++) a[i]=-1;
    for(int i=1;i<=q;i++){
        cin >>e[i].c>>e[i].l>>e[i].r;
        if(e[i].c==1) {
            for(int j=e[i].l;j<=e[i].r;j++){
                a[j]=k;
            }
        }
    }
    sort(e+1,e+1+q,cmp);
    for(int i=1;i<=q;i++){
        if(e[i].c==2){
            int now=0;
            for(int j=0;j<k;j++) v[j]=0;
            for(int j=e[i].l;j<=e[i].r;j++){
                if(a[j]>=0&&a[j]<=k-1) v[a[j]]=1;
            }
            for(int j=e[i].l;j<=e[i].r;j++){
                while(v[now]==1&&now<k) now++;
                if(a[j]==k) a[j]=k+1;
                //else if(a[j]!=-1) v[a[j]]=1;
                else if(a[j]==-1){
                    if(v[now]==0&&now<k){
                        v[now]=1;
                        a[j]=now;
                    }
                }
                
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==-1) cout <<k+1<<" ";
        else cout <<a[i]<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}