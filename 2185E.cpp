#include <bits/stdc++.h>
using namespace std;
int T,n,m,k;
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
int vis[200005],a[200005],b[200005];
string ch;
int find1(int x){
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)/2;
        if(b[mid]<x) l=mid+1;
        else r=mid-1;
    }
    int now;
    for(int i=max(0,l+2);i>=min(m,l-2);i--){
        if(b[i]>x) now=i;
    }
    return b[now];
}
int find2(int x){
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)/2;
        if(b[mid]<x) l=mid+1;
        else r=mid-1;
    }
    int now;
    for(int i=max(0,l-2);i<=min(m,l+2);i++){
        if(b[i]<x) now=i;
    }
    return b[now];
}
void solve(){
    map<int,vector<int>> Q;
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) b[i]=read();
    cin >>ch;
    sort(b+1,b+1+m);
    for(int i=1;i<=n;i++){
        if(a[i]>b[1]){
            int pos=find2(a[i])-a[i];
            Q[pos].push_back(i);
        }
        if(a[i]<b[m]){
            int pos=find1(a[i])-a[i];
            Q[pos].push_back(i);           
        }
    }
    for(int i=1;i<=n;i++) vis[i]=0;
    int now=0,ans=n;
    for(int i=0;i<k;i++){
        if(ch[i]=='L') now--;
        else now++;
        if(Q[now].size()!=0){
            for(int j=0;j<Q[now].size();j++){
                if(vis[Q[now][j]]==0){
                    vis[Q[now][j]]=1;
                    ans--;
                } 
            }
            Q[now].clear();            
        }

        cout <<ans<<" ";
    }
    cout <<"\n";
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}