#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,x;
int a[200005],ans[200005],cnt;
bool check(int qwq){
    cnt=0;
    int sum;
    if(qwq==0) sum=x+1;
    else{
        qwq--;
        sum=0;
        sum+=max(0ll,a[1]-qwq);
        sum+=max(0ll,x-a[n]-qwq);
        for(int i=1;i<n;i++){
            sum+=max(a[i+1]-a[i]-qwq*2-1ll,0ll);
        }
    }
    if(sum>=k) return true;
    return false;

    /*
    if(a[1]>qwq) return false;
    if(a[n]+qwq<x) return false;
    for(int i=1;i<=n;i=nxt){
        int t=a[i]+qwq*2;
        ans[++cnt]=a[i]+qwq;
        while(a[nxt]<=t) nxt++;
    }
    if(cnt<=k) return true;
    else return false;*/
}
void print(int qwq){
    if(qwq==0){
        for(int i=0;i<k;i++){
            cout <<i<<" ";
        }
        cout <<endl;
    }
    else{
        qwq--;
        for(int i=0;i<a[1]-qwq;i++){
            if(k>0){
                cout <<i<<" ";
                k--;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=a[i]+qwq+1;j<=a[i+1]-qwq-1;j++){
                if(k>0){
                    cout <<j<<" ";
                    k--;
                }
            }
        }
        for(int i=a[n]+qwq+1;i<=x;i++){
            if(k>0){
                cout <<i<<" ";
                k--;
            }
        }
        cout <<endl;
    }
    return ;
}
void solve(){
    cin >>n>>k>>x;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    sort(a+1,a+1+n);
    a[n+1]=1e12;
    int l=0,r=x;
    while(l<r){
        int mid=(l+r)/2;
        //cout <<mid<<endl;
        if(check(mid)==true) l=mid+1;
        else r=mid-1;
    }
    for(int i=min(l+2,x);i>=max(0ll,l-2);i--){
        if(check(i)==true){
            //cout <<i<<" "<<cnt<<endl;
            print(i);
            return ;
        }
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
/*
1
15 7 12
8 12 9 12 7 3 3 4 11 8 1 12 1 8 9
*/