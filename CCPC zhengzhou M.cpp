#include <bits/stdc++.h>
using namespace std;
int n,k,a[100005];
double ans[100005];
bool check(double x){
    double sum=x;
    ans[1]=x;
    for(int i=2;i<=n;i++){
        ans[i]=(a[i]*x)/(a[1]+a[i]*x-a[1]*x);
        sum+=ans[i];
    }
    if(sum-(double)k>1e-8) return true;
    return false;
}
int main(){
    cin >>n>>k;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    double l=0.00,r=1.00;
    while(r-l>1e-8){
        double mid=(l+r)/2.00;
        if(!check(mid)) l=mid;
        else r=mid;
    }
    check(l);
    for(int i=1;i<=n;i++){
        printf("%.7lf\n",ans[i]);
    }
    return 0;
}