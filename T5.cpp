#include <bits/stdc++.h>
using namespace std;
int n,a[1003],b[1003],ans,sum;

int main(){
    cin >>n;
    for(int i=1;i<=n;i++){
      cin >>a[i];
    }
    for(int i=1;i<=n;i++){
        cin >>b[i];
    }
    for(int i=1;i<=n;i++){
      sum=10000;
       for(int j=1;j<=n;j++){
          sum=min(sum,abs(a[i]-b[j]));
       }
       ans=max(ans,sum);
    }
  cout <<ans;
  return 0;
}