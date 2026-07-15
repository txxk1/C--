#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,d;
int a[100005],b[100005];
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
int get(int x,int y){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]>y) b[i]=y;
        else if(a[i]<x) b[i]=x;
        else b[i]=a[i];
    }
    for(int i=1;i<n;i++) sum+=abs(b[i+1]-b[i]);
    return sum;
}
void solve(){
    int ans=0;
    cin >>n>>d;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    for(int i=1;i<=n;i++){
        int L=a[i],R=a[i]+d;
        int l=a[i]-d,r=a[i];
        ans=max(ans,get(L,R));
        ans=max(ans,get(l,r));
    }
    cout <<ans<<endl;
}
signed main(){
    solve();
    return 0;
}