#include <bits/stdc++.h>

using namespace std;
int n,k,cnt;
string a;
string ans[205];
map<string,int> f;
int main(){
    cin >>n>>k;
    cin >>a;
    for(int i=0;i<=n-k;i++){
        string x;
        for(int j=i;j<=i+k-1;j++){
            x+=a[j];
        }
        f[x]++;
    }
    int sum=0;
    for(int i=0;i<=n-k;i++){
        string x;
        for(int j=i;j<=i+k-1;j++){
            x+=a[j];
        }
        sum=max(sum,f[x]);
    }
    cout <<sum<<endl;
    for(int i=0;i<=n-k;i++){
        string x;
        for(int j=i;j<=i+k-1;j++){
            x+=a[j];
        }
        if(f[x]==sum){
            f[x]=0;
            ans[++cnt]=x;
        }
    }
    sort(ans+1,ans+1+cnt);
    for(int i=1;i<=cnt;i++) cout <<ans[i]<<" ";
    return 0;
}