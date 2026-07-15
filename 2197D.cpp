#include <bits/stdc++.h>
#define debug cout <<i<<" "<<j<<endl;
#define int long long
using namespace std;
int T,n;
int a[200005];
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
vector<int> Q[200005];
void solve(){
    int ans=0;
    n=read();
    for(int i=1;i<=n;i++) Q[i].clear();
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i]<=n) Q[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                if(j*j==i){
                    map<int,int> p;
                    for(int k=0;k<Q[j].size();j++){
                        p[Q[j][k]]=1;
                    }
                    for(int k=0;k<Q[j].size();k++){
                        if(p[Q[j][k]+i]==1) ans++;
                    }
                }
                if(Q[j].size()>0&&Q[i/j].size()>0){
                    if(Q[j].size()<Q[i/j].size()){
                        for(int k=0;k<Q[j].size();k++){
                            if(Q[j][k]+i<=n&&Q[j][k]+i>=1){
                                if(a[Q[j][k]+i]==(i/j)) ans++;
                                debug
                            }
                            if(Q[j][k]-i<=n&&Q[j][k]-i>=1){
                                if(a[Q[j][k]-i]==(i/j)) ans++;
                                debug
                            }
                        }
                    }
                    else{
                        for(int k=0;k<Q[i/j].size();k++){
                            if(Q[i/j][k]+i<=n&&Q[i/j][k]+i>=1){
                                if(a[Q[i/j][k]+i]==j) ans++;
                                debug
                            }
                            if(Q[i/j][k]-i<=n&&Q[i/j][k]-i>=1){
                                if(a[Q[i/j][k]-i]==j) ans++;
                                debug
                            }
                        }
                    }
                }
            }
        }
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}