#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],s[500005],cnt;
int vis[1<<20];
vector<int> b;
void init(){
    for(int j=0;j<b.size();j++) vis[b[j]]=0;
    b.clear();
    return ;
}
void solve(){
    cin >>n>>k;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    //vis[0]=1;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]^a[i];
        if(s[i]==k){
            init();
            s[i]=0;
            cnt++;
            continue;
        }
        if(vis[s[i]]==0){
            b.push_back(s[i]);
            vis[s[i]]=1;
        }
        else vis[s[i]]++;
        if(k==0){
            if(vis[s[i]]>=2){
                init();
                s[i]=0;
                cnt++;
            }
        }
        if(k!=0&&vis[s[i]^k]>=1){
            init();
            s[i]=0;
            //vis[0]=1;
            cnt++;
        }
    }
    cout <<cnt;
    return ;
}

signed main(){
    //freopen("xor6.in","r",stdin);
    solve();
    return 0;
}