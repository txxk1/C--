#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y;
int a[200005],ans[200005],nxt[400005],cnt,qwq[400005],qwqcnt,l[400005];
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
void solve(){
    n=read(),x=read(),y=read();
    x++;
    cnt=0;
    qwqcnt=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<x;i++) nxt[++cnt]=a[i];
    for(int i=y+1;i<=n;i++) nxt[++cnt]=a[i];
    sort(nxt+1,nxt+1+cnt);
    int minn=1e9;
    for(int i=x;i<=y;i++){
        qwq[++qwqcnt]=a[i];
        minn=min(minn,a[i]);
    }
    vector<int> sb;
    for(int i=1;i<=qwqcnt;i++){
        if(qwq[i]==minn) sb.push_back(i);
    }
    while(1){
        for(int i=1;i<=qwqcnt;i++){
            
        }
    }
    //for(int i=1;i<=qwqcnt;i++) qwq[i+cnt]=qwq[i];
    for(int i=1;i<=cnt;i++){
        if(nxt[i]<qwq[1]) cout <<nxt[i]<<" ";
        
    }
    cout <<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}