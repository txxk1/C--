#include <bits/stdc++.h>
#define int long long
#define inf 1e9
using namespace std;
int T,n,l,r,a[200005],v[105],b[200005],cnt;
struct node{
    int c,l,r;
}e[105];
bool cmp(node a,node b){
    return a.l<b.l;
}

void solve(){
    int ans=0,plus=0,neg=0,cpl=0,cneg=0;
    map<int,int> f;
    cin >>n>>l>>r;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        if(a[i]>=l&&a[i]<=r) f[a[i]]++,b[++cnt]=a[i];
        if(a[i]<l) plus+=a[i],cpl++;
        if(a[i]>r) neg+=a[i],cneg++;
    }
    sort(a+1,a+1+n);
    //sort(b+1,b+1+cnt);
    int qwq=n/2+(n%2);
    int now=a[qwq];
    if(a[qwq]<l) now=l;
    if(a[qwq]>r) now=r;
    for(int i=1;i<=n;i++){
        ans+=abs(now-a[i]);
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// 5+3+1+1+3