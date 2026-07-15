#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans;
int a[2][200005],minn[2][200005],maxn[2][200005];
struct node{
    int l,r;
}x[200005];
bool cmp(node a,node b){
    return a.r<b.r;
}
void solve(){
	cin >>n;
    minn[0][0]=1e9;
    minn[1][n+1]=1e9;
    maxn[0][0]=-1;
    maxn[1][n+1]=-1;
    for(int i=1;i<=n;i++){
        cin >>a[0][i];
        minn[0][i]=min(minn[0][i-1],a[0][i]);
        maxn[0][i]=max(maxn[0][i-1],a[0][i]);
    }
    for(int i=1;i<=n;i++){
        cin >>a[1][i];
    }
    for(int i=n;i>=1;i--){
        minn[1][i]=min(minn[1][i+1],a[1][i]);
        maxn[1][i]=max(maxn[1][i+1],a[1][i]);
    }
    for(int i=1;i<=n;i++){
        x[i].l=min(minn[0][i],minn[1][i]);
        x[i].r=max(maxn[0][i],maxn[1][i]);
    }
    sort(x+1,x+1+n,cmp);
    ans=(x[1].l)*(2ll*n+1ll-x[1].r);
    int now=x[1].l;
    for(int i=2;i<=n;i++){
        if(x[i].l>now){
            ans+=(x[i].l-now)*(2ll*n+1ll-x[i].r);
            now=x[i].l;
        }
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}