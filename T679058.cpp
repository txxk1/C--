#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[300005],c[300005],l,r,ans;
int gcd(int x,int y){
    if(y==0) return x;
    //if(x<y) return gcd(y,x);
    return gcd(y,x%y);
}
void solve(){
    cin >>n>>k;    
    ans=0;
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        //ans=gcd(ans,a[i]);
        c[i]=a[i]-a[i-1];
        ans=gcd(ans,abs(c[i]));
    }    
    if(k==0){
        cout <<ans<<endl;
        return ;
    }
    l=-1;
    r=-1;
    for(int i=2;i<=n;i++){
        int aa=gcd(abs(c[i-1]),abs(c[i]+k));
        int bb=gcd(abs(c[i-1]),abs(c[i]));
        int cc=gcd(abs(c[i+1]),abs(c[i]+k));
        int dd=gcd(abs(c[i+1]),abs(c[i]));
        if(aa>=bb&&cc>=dd&&aa+cc>bb+dd){
            l=i;
            break;
        }
    }
    for(int i=n-1;i>=1;i--){
        int aa=gcd(abs(c[i-1]),abs(c[i]-k));
        int bb=gcd(abs(c[i-1]),abs(c[i]));
        int cc=gcd(abs(c[i+1]),abs(c[i]-k));
        int dd=gcd(abs(c[i+1]),abs(c[i]));
        if(aa>=bb&&cc>=dd&&aa+cc>bb+dd){
            r=i;
            break;
        }
    }
        int sum=0;
        for(int i=1;i<=n;i++){
            if(i==l){
                sum=gcd(sum,abs(c[i]+k));
            }
            else if(i==r) sum=gcd(sum,abs(c[i]-k));
            else sum=gcd(sum,abs(c[i]));
            //cout <<sum<<" ";
        }
        cout <<max(sum,ans)<<endl;
    
    return ;
}
signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}/*
2
7 2
7 7 5 12 14 21 42
*/