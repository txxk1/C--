#include <bits/stdc++.h>

using namespace std;
int T,n,q,a[250005],t[250005],s[250005],to[250005],p[33],st[250005];
int find(int x,int now){
    int i;
    for(i=1;i<=30;i++){
        if(x<=p[i]){
            if(x==p[i-1]+1&&x!=2){
                t[now]=1;
                return i-1;
            }
            return i;
        }
    }
    return 30;
}
int query(int l,int r){
    if(st[r]-st[l-1]==0) return s[r]-s[l-1];
    else return s[r]-s[l-1]+(st[r]-st[l-1])/2;
}
void init(){
    p[0]=1;
    for(int i=1;i<=30;i++) p[i]=p[i-1]*2;
    return ;
}
void solve(){
    cin >>n>>q;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        t[i]=0;
        a[i]=find(a[i],i);
        s[i]=s[i-1]+a[i];
        st[i]=st[i-1]+t[i];
    }
    for(int i=1;i<=q;i++){
        int l,r;
        cin >>l>>r;
        cout <<query(l,r)<<endl;
    }
    //for(int i=1;i<=n;i++) cout <<t[i]<<" ";
    return ;
}
int main(){
    cin >>T;
    init();
    while(T--) solve();
    return 0;
}