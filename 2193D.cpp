#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
int a[200005],b[200005],s[200005];
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
int find(int x){
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        //  l x mid   r
        if(s[mid]>x) r=mid-1;
        //else if(s[mid]==x) return mid;
        else l=mid+1;
    }
    int qwq=0;
    for(int i=max(1ll,l-2);i<=min(n,l+2);i++){
        if(s[i]<=x) qwq=i;
    }
    return qwq;
}
void solve(){
    vector<int>Q;
    map<int,int> S;
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    a[n+1]=0;
    for(int i=1;i<=n;i++) b[i]=read(),s[i]=s[i-1]+b[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int now=a[i],j;
        for(j=i+1;j<=n;j++){
            if(a[j]!=now) break;
        }
        S[a[i]]=n-i+1;
        Q.push_back(a[i]);
        i=j-1;
        
    }
    int ans=0;
    for(int i=0;i<Q.size();i++){
        int now=Q[i];
        ans=max(ans,now*find(S[now]));
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}
// an^(n-1)==an-1