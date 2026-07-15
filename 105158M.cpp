#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[300005],b[300005];
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
bool check(int k){
    int L=a[1]-k*b[1],R=a[1]+k*b[1],flag=1;
    for(int i=2;i<=n;i++){
        int LL=a[i]-k*b[i],RR=a[i]+k*b[i];
        L=max(L,LL);
        R=min(R,RR);
    }
    return L<=R;
}
void solve(){
    int ans=0;
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=n;i++) cin >>b[i];
    int l=0ll,r=1000000000ll;
    while(l<r){
        int mid=(l+r)/2;
        if(!check(mid)) l=mid+1;
        else r=mid-1;
    }
    // fff ttttt
    for(int i=max(l-2,0ll);i<=min(l+2,1000000000ll);i++){
        if(check(i)){
            ans=i;
            break;
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
