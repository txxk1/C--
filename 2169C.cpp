#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
int a[200005],s[200005],cnt,c[200005];

void solve(){
    int ans=0;
    int sum=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        sum+=a[i];
        //s[i]=s[i-1]+a[i];
        c[i]=a[i]-2*i;
        s[i]=s[i-1]-c[i];
    }
    // ( s[r]-s[l-1] )max
    int lst=0;
    for(int i=1;i<=n;i++){
        //now=max(now,s[i]);
        //cout <<s[i]<<" ";
        ans=max(ans,s[i]-lst);
        lst=min(lst,s[i]);
    }
    //cout <<endl;
    // 
    for(int i=1;i<=n;i++) c[i]=0,s[i]=0;
    // -1 5 9 -6 7
    // now [1,r] max
    // lst [1,l-1] min
    cout <<sum+ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// a1-2
// a2-4
// a3-6
// l,r
// x1,x2,x3
// (x2-x1+1)*(x1+x2)+(x3-x2)*(x3+x2+1)==x2^2-x^12+x1+x2+x3^2-x2^2+x3
// (x3-x1+1)*(x1+x3)==x3^2-x1^2+x1+x3
// cost(x1,x2)+cost(x2+1,x3) == cost(x1,x3)
// s[x1,x2]+s[x2+1,x3] == s[x1,x3]
// max(cost(len)-s[len],0)