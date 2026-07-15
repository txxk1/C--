#include <bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;
int T,n,m,ans,b[500005],sum,c[500005],ans2,invjie[500005],jie[500005],inv[500005];
struct node{
    int id,v;
}h[1000005];
bool cmp(node x,node y){
    if(x.v==y.v) return x.id<y.id;
    return x.v>y.v;
}
int C(int x,int y){
    return (jie[x]*invjie[y]%MOD)*invjie[x-y]%MOD;
}
void solve(){
    inv[1]=1;
    jie[1]=1;
    for(int i=2;i<=n;i++){
        jie[i]=jie[i-1]*i%MOD;
        inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
        invjie[i]=invjie[i-1]*inv[i]%MOD;
    }
    int cnt=0;
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        cin >>h[i].v;
        h[i].id=2;
    }
    for(int i=n+1;i<=n+m;i++){
        cin >>h[i].v;
        h[i].id=1;
    }
    sort(h+1,h+1+n+m,cmp);
    for(int i=1;i<=n+m;i++){
        if(h[i].id==2){
            cnt++;
        }
        else{
            if(cnt>0){
                ans+=h[i].v;
                cnt--;
                b[++sum]=i;
            }
        }
    }
    int now=1,S=0;
    for(int i=1;i<=n+m;i++){
        if(h[i].id==2){
            S++;
        }
        if(b[now]==i){
            c[now]=S;
            now++;
        }
    }
    cout <<now<<endl;
    ans2=1;
    for(int i=1;i<=sum;i++){
        cout <<c[now]-i+1<<" ";
        ans2=(ans2*C(c[now]-i+1,1))%MOD;
    }
    cout <<ans<<" "<<ans2;
    return ;
}
signed main(){
    solve();
    return 0;
}