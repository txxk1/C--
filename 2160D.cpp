#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,T,a[605],cnt,b[605];
void solve(){
    cnt=0;
    int lst,x;
    for(int i=1;i<=600;i++) a[i]=0;
    cin >>n;
    for(int i=2;i<=n*2;i++){
        int sum=0;
        cout <<"? ";
        for(int j=1;j<=i;j++){
            if(a[j]==0) sum++;//cout <<j<<" ";
        }
        cout <<sum<<" ";
        for(int j=1;j<=i;j++){
            if(a[j]==0) cout <<j<<" ";
        }
        cout <<endl;
        cin >>x;
        if(x==0) continue;
        else{
            a[i]=x;
            b[++cnt]=i;
        }
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n*2;i++){
        if(a[i]!=0) continue;
        int flag=0;
        cout <<"? ";
        cout <<n+1<<" ";
        for(int j=1;j<=n;j++){
            if(b[j]<i) cout <<b[j]<<" ";
            else if(flag==0){
                cout <<i<<" "<<b[j]<<" ";
                flag=1;
            }
            else if(flag==1) cout <<b[j]<<" ";
        }
        cout <<endl;
        cin >>x;
        a[i]=x;
    }
    cout <<"! ";
    for(int i=1;i<=n*2;i++){
        cout <<a[i]<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}