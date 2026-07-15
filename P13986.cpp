#include <bits/stdc++.h>

using namespace std;
int n,m;
string x[5005],y[5005],ans[1005];
map<string,int> b;
int main(){
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>x[i]>>y[i];
        //a[x]++;
        b[y[i]]++;
    }
    cin >>m;
    for(int i=1;i<=m;i++){
        string qwq;
        cin >>qwq;
        int flag=0;
        for(int j=1;j<=n;j++){
            if(x[j]==qwq&&b[y[j]]>=2){
                flag=j;
                break;
            }
        }
        if(flag==0){
            ans[i]=qwq;
            continue;
        }
        for(int j=1;j<=n;j++){
            if(y[j]==y[flag]&&j!=flag){
                ans[i]=x[j];
                break;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout <<ans[i]<<" ";
    }
    return 0;
}